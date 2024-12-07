/*********************************************************************
 * @file  Button.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Button.h"
#include <Arduino.h>

//#define BUTTON_PIN D8

Button::Button(int pin) : Peripheral("Button"), pin(pin) {};

void Button::Button::init() {
  Serial.begin(115200);
  pinMode(pin, INPUT);
}

bool Button::isPress() {
  int buttonState = digitalRead(pin);
    if(buttonState == LOW) {
      return false;
    }
    else{
      return true;
    }
}
