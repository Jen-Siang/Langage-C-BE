/*********************************************************************
 * @file  Button.cpp
 * @author Lin Jen-Siang - Revelli Julie
 * @brief Implementation file for the Button class
 *********************************************************************/
#include "Button.h"
#include <Arduino.h>

//#define BUTTON_PIN D8

/**
* @brief for the Button class
* @param pin
*/
Button::Button(int pin) : Peripheral("Button"), pin(pin) {};

/**
* @brief Initializes the button
*/
void Button::Button::init() {
  Serial.begin(115200);   // Start the serial connection at 115200 baud.
  pinMode(pin, INPUT);    // Set the specified pin as an input pin.
}

/**
* @brief Checks if the button is pressed
* @return true if the button is pressed, false otherwise
*/
bool Button::isPress() {
  int buttonState = digitalRead(pin); // Read the current state of the pin
    if(buttonState == LOW) {
      return false; // Button is not pressed
    } else {
      return true; // Button is pressed
    }
}
