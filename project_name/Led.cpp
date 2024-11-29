/*********************************************************************
 * @file  Led.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Led.h"
#include <Arduino.h>

#define LED_PIN D5

Led::Led(){
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

Led::~Led(){;}

void Led::low(){
  digitalWrite(LED_PIN, LOW);
}
void Led::high(){
  digitalWrite(LED_PIN, HIGH);
}
