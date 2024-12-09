/*********************************************************************
 * @file  Apllication.cpp
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Peripheral.h"
#include "Application.h"
#include "Button.h"
#include "Led.h"
#include "LCD.h"
#include "rotaryAngleSensor.h"
#include "PeripheralException.h"
#include <vector>
#include <Arduino.h>


Application::Application() {}
  
Application::~Application() {}

/**
 * @brief Initializes the application
 */
void Application::init(void)
{
    Serial.begin(115200);   // Open serial communication at 115200 baud
    Serial.println("Initialisation réussie");
}

/**
 * @brief Main method to run the application
 */
void Application::run(void)
{
  // Create instances of peripherals
  LCD myLCD;
  Button startButton(D8);                // Button connected to pin D8
  Led myLed(D5);                         // LED connected to pin D5
  rotaryAngleSensor rotationSensor(A0);  // Rotary angle sensor connected to A0

  // Initialize all peripherals
  myLCD.init();
  startButton.init();
  myLed.init();
  rotationSensor.init();
 
  try{
    // Wait until the button is pressed to start the game
    while (!startButton.isPress()) {
      myLCD.clear();
      myLCD << "Press button";       // Display prompt on the LCD
      myLCD.setCursor(0, 1);         // Move cursor to the second line
      myLCD << "to start";           // Display prompt continuation
      delay(500);
    }
  
    // Signal game start via serial output
    Serial.println("start_game");
    delay(500);

    // Main game loop
    while(true){
      myLed.high(); // Turn on the LED to indicate game activity
      
      // Check if the serial port is unavailable
      if (Serial.available() < 0) {  
        throw PeripheralException("Serial port unavailable"); // Throw an exception if the serial port is not accessible
      }
      
      // If data is available on the serial port
      if (Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');  // Read the serial message until a newline character
        
        // Handle incoming messages
        // When the message is "score:"
        if (message.startsWith("score:")) {
            String score = message.substring(6);  // Extract the score value
            delay(500);
            myLCD.clear(); // Clear the LCD
            myLCD << "Game started"; // Display Game started message
            myLCD.setCursor(0, 1);
            myLCD << "Score:"; // Display Score message on the second line
            myLCD.setCursor(7, 1);
            myLCD.message(score); // Display the score on the LCD
        }
        
        //When the message is "game_over"
        if (message.startsWith("game_over")) {
          myLed.low(); // Turn off the LED
          myLCD.clear(); // Clear the LCD
          myLCD << "Game Over"; // Display game over message

          // Wait until the button is pressed to restart the game
          while (!startButton.isPress()) {
            delay(500);
          }
          break; //exit the game loop
        }   
      }
      
      rotationSensor.run(); // Continuously update the rotary sensor data
    }
  // Handle any peripheral-related exceptions
  } catch (const PeripheralException& e) {
    Serial.print("Erreur : ");
    Serial.println(e.getMessage());  // Print the error message to the serial console
  }
}
