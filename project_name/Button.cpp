/*********************************************************************
 * @file  Button.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Button.h"
#include <Arduino.h>

#define BUTTON_PIN D8

Button::Button(){
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(115200);
  Serial.println("test");
}

Button::~Button(){;}

bool Button::isPress(){
  int buttonState = digitalRead(BUTTON_PIN);
    if(buttonState == LOW){
      //Serial.println("Button not pressed");
      return false;
    }
    else{
      //Serial.println("Button pressed");
      return true;
    }
}
