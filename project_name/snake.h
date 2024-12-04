#ifndef SNAKE_H
#define SNAKE_H

#ifdef __cplusplus
extern "C" {
#endif

void snake_draw_board();
void snake_draw_fruit();
bool snake_move_player(int direction);
void snake_game_over();
void snake_run();

#ifdef __cplusplus
}
#endif

#endif
