# Langaga-C-BE

## SNAKE GAME

### Description
This project implements a C++ application on a NodeMCU board with peripherals like a button, an LED, an LCD screen, and a rotary angle sensor. The goal is to integrate an interactive game (Snake) with advanced features, such as:

* Peripheral management using C++ classes.
* Advanced C++ concepts:
    * Exceptions.
    * Operator overloading.
* Serial communication with a terminal to display the game.

### Prerequisites
#### 1. Hardware:
* NodeMCU ESP8266.
* Button (connected to D8).
* LED (connected to D5).
* I2C-compatible RGB LCD screen.
* Rotary angle sensor (connected to A0).

#### 2. Software:
* Arduino IDE (version 1.8.19 or newer).
* Grove - LCD RGB Backlight library installed.

#### 3. Configuration:
* Board: NodeMCU 1.0 (ESP-12E Module).
* Serial baud rate: 115200.
* Exceptions enabled in platform.txt.

### How to start
1. Clone this repository:
```
git clone https://github.com/Jen-Siang/Langage-C-BE.git
```

2. Open snake_game.ino in the Arduino IDE.

3. Ensure all dependencies are installed:
* Grove - LCD RGB Backlight library.
* NodeMCU drivers.
* snake.c relies on ncurses to draw to the terminal. To install on Ubuntu/Debian, use:

```
sudo apt-get install lib32ncurses5-dev
```

4. Upload the code to your board using the Arduino IDE.

5. Open a terminal where you clone the repository and run
    ```
    gcc snake.c -o snake -lncurses
    ./snake
    ```
    * The LCD screen will display Press button to start
    * Press the button to start the game.
    * Use the rotary angle sensor to control the snake.
    * The score is displayed in real-time on the LCD screen.
    * If Game Over occurs, restart the game by pressing the button again.

### Ressource
We use and modify the c code of : https://github.com/mnisjk/snake/blob/master/snake.c