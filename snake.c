#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <sys/select.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <pthread.h>

#define DESIRED_WIDTH  35
#define DESIRED_HEIGHT 15

int fd;
bool start = false;
int direction = 0;
pthread_mutex_t direction_mutex = PTHREAD_MUTEX_INITIALIZER;

WINDOW * g_mainwin;
int g_oldcur, g_score = 0, g_width, g_height;
typedef struct {
    int x;
    int y;
} pos;
pos fruit;

// 2D array of all spaces on the board.
bool *spaces;

// --------------------------------------------------------------------------
// Queue stuff

// Queue implemented as a doubly linked list
struct s_node
{
    pos *position; // **TODO: make this a void pointer for generality.
    struct s_node *prev;
    struct s_node *next;
} *front=NULL, *back=NULL;
typedef struct s_node node;

// Returns the position at the front w/o dequeing
pos* peek( )
{
    return front == NULL ? NULL : front->position;
}

// Returns the position at the front and dequeues
pos* dequeue( )
{
    node *oldfront = front;
    front = front->next;
    return oldfront->position;
}

// Queues a position at the back
void enqueue( pos position )
{
   pos *newpos   = (pos*)  malloc( sizeof( position ) ); 
   node *newnode = (node*) malloc( sizeof( node ) );

   newpos->x = position.x;
   newpos->y = position.y;
   newnode->position = newpos;

   if( front == NULL && back == NULL )
       front = back = newnode;
   else
   {
       back->next = newnode;
       newnode->prev = back;
       back = newnode;
   }
}
// --------------------------------------------------------------------------
// End Queue stuff

// --------------------------------------------------------------------------
// Snake stuff

// Writes text to a coordinate
void snake_write_text( int y, int x, char* str )
{
    mvwaddstr( g_mainwin, y , x, str );
}

// Draws the borders
void snake_draw_board( )
{
    int i;
    for( i=0; i<g_height; i++ )
    {
        snake_write_text( i, 0,         "X" );
        snake_write_text( i, g_width-1, "X" );
    }
    for( i=1; i<g_width-1; i++ )
    {
        snake_write_text( 0, i,          "X" );
        snake_write_text( g_height-1, i, "X" );
    }
    snake_write_text( g_height+1, 2, "Score:" );
}

// Resets the terminal window and clears up the mem
void snake_game_over( )
{
    char game_over_message[15];
    sprintf(game_over_message, "game_over\n");
    write(fd, game_over_message, strlen(game_over_message));
    
    free( spaces );
    while( front )
    {
        node *n = front;
        front = front->next;
        free( n );
    }
    endwin();
    exit(0);
}

// Is the current position in bounds?
bool snake_in_bounds( pos position )
{
    return position.y < g_height - 1 && position.y > 0 && position.x < g_width - 1 && position.x > 0;
}

// 2D matrix of possible positions implemented with a 1D array. This maps
// the x,y coordinates to an index in the array.
int snake_cooridinate_to_index( pos position )
{
    return g_width * position.y + position.x;
}

// Similarly this functions maps an index back to a position
pos snake_index_to_coordinate( int index )
{
    int x = index % g_width;
    int y = index / g_width;
    return (pos) { x, y };
}

// Draw the fruit somewhere randomly on the board
void snake_draw_fruit( )
{
    attrset( COLOR_PAIR( 3 ) );
    int idx;
    do
    {
        idx = rand( ) % ( g_width * g_height );
        fruit = snake_index_to_coordinate( idx );
    }
    while( spaces[idx] || !snake_in_bounds( fruit ) );    
    snake_write_text( fruit.y, fruit.x, "F" );
}

// Handles moving the snake for each iteration
bool snake_move_player( pos head )
{
    attrset( COLOR_PAIR( 1 ) ) ;
    
    // Check if we ran into ourself
    int idx = snake_cooridinate_to_index( head );
    if( spaces[idx] )
        snake_game_over( );
    spaces[idx] = true; // Mark the space as occupied
    enqueue( head );
    g_score += 10;
    
    // Check if we're eating the fruit
    if( head.x == fruit.x && head.y == fruit.y )
    {
        snake_draw_fruit( );
        g_score += 1000;
    }
    else
    {
        // Handle the tail
        pos *tail = dequeue( );
        spaces[snake_cooridinate_to_index( *tail )] = false;
        snake_write_text( tail->y, tail->x, " " );
    }
    
    // Draw the new head 
    snake_write_text( head.y, head.x, "S" );
    
    // Update scoreboard
    char buffer[25];
    sprintf( buffer, "%d", g_score );
    attrset( COLOR_PAIR( 2 ) );
    snake_write_text( g_height+1, 9, buffer );

    char score_message[50];
    sprintf(score_message, "score:%d\n", g_score);
    int bytes_written = write(fd, score_message, strlen(score_message));
    //printf("Score sent:%s (bytes written:%d)\n", score_message, bytes_written);
}

void* serial_listener(void* arg) {
    //printf("Serial listener thread started\n");
    char input[100];
    
    while (1) {
        int n = read(fd, input, sizeof(input) - 1);
        if (n == -1) {
            perror("Error reading from serial port");
        }
        if (n > 0) {
            input[n] = '\0';
            //printf("Received input: '%s'\n", input);
            if (strncmp(input, "start_game", 10) == 0) {
                start = true;
            } else if (strncmp(input, "up", 2) == 0) {
                pthread_mutex_lock(&direction_mutex);
                direction = 1;  // UP
                pthread_mutex_unlock(&direction_mutex);
            } else if (strncmp(input, "right", 5) == 0) {
                pthread_mutex_lock(&direction_mutex);
                direction = 2;  // RIGHT
                pthread_mutex_unlock(&direction_mutex);
            } else if (strncmp(input, "down", 4) == 0) {
                pthread_mutex_lock(&direction_mutex);
                direction = 3;  // DOWN
                pthread_mutex_unlock(&direction_mutex);
            } else if (strncmp(input, "left", 4) == 0) {
                pthread_mutex_lock(&direction_mutex);
                direction = 4;  // LEFT
                pthread_mutex_unlock(&direction_mutex);
            }
        }
        sleep(1);
    }
    return NULL;
}

void snake_run()
{
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening serial port");
        exit(1);
    } else {
        //printf("Serial port opened successfully, fd = %d\n", fd);
    }

    struct termios tty;
    tcgetattr(fd, &tty);

    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    tcsetattr(fd, TCSANOW, &tty);
    tcflush(fd, TCIOFLUSH);

    if( ( g_mainwin = initscr() ) == NULL ) {
        perror( "error initialising ncurses" );
        exit( EXIT_FAILURE );
    }
    
    // Set up
    srand( time( NULL ) );
    noecho( );
    curs_set( 2 );
    halfdelay( 1 );
    keypad( g_mainwin, TRUE );
    g_oldcur = curs_set( 0 );
    start_color( );
    init_pair( 1, COLOR_RED,     COLOR_BLACK );
    init_pair( 2, COLOR_GREEN,   COLOR_BLACK );
    init_pair( 3, COLOR_YELLOW,  COLOR_BLACK );
    init_pair( 4, COLOR_BLUE,    COLOR_BLACK );
    init_pair( 5, COLOR_CYAN,    COLOR_BLACK );
    init_pair( 6, COLOR_MAGENTA, COLOR_BLACK );
    init_pair( 7, COLOR_WHITE,   COLOR_BLACK );
    getmaxyx( g_mainwin, g_height, g_width );
    
    g_width  = g_width  < DESIRED_WIDTH  ? g_width  : DESIRED_WIDTH;
    g_height = g_height < DESIRED_HEIGHT ? g_height : DESIRED_HEIGHT; 
    
    // Set up the 2D array of all spaces
    spaces = (bool*) malloc( sizeof( bool ) * g_height * g_width );

    snake_draw_board( );
    snake_draw_fruit( );
    pos head = { 5,5 };
    enqueue( head );
    
    speed_t input_speed = cfgetispeed(&tty);
    speed_t output_speed = cfgetospeed(&tty);

    printf("Input Baud Rate: %d\n", (int)input_speed);
    printf("Output Baud Rate: %d\n", (int)output_speed);
    printf("Waiting for 'start_game' command to start...\n");

    pthread_t serial_thread;
    pthread_create(&serial_thread, NULL, serial_listener, NULL);

    while(!start){
        //mvwaddstr(g_mainwin, g_height / 2, g_width / 2 - 7, "Waiting for start...");
        wrefresh(g_mainwin);
        sleep(1);
        //printf("start : %d\n", start);
    }

    // Event loop
    while( 1 )
    {
        //printf("Game started\n");
        pthread_mutex_lock(&direction_mutex);  // Protéger l'accès à `direction`
        int current_direction = direction;
        pthread_mutex_unlock(&direction_mutex);
        switch( current_direction )
        {
            case 3: // DOWN
                head.y++;
                break;
            case 2: // RIGHT
                head.x++;
                break;
            case 1: // UP
                head.y--;
                break;
            case 4: //LEFT
                head.x--;
                break;
        }
        //printf("new position = %d", head.x);
        if( !snake_in_bounds( head ) )    
            snake_game_over( );
        else
            snake_move_player( head );
            wrefresh(g_mainwin);
        sleep(1);
    }
    snake_game_over( );
    close(fd);
}

int main( int argc, char *argv[] ){
    snake_run();
}

