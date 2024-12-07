/*********************************************************************
 * @file  Led.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Led.h"
#include <Arduino.h>

//#define LED_PIN D5

Led::Led(int pin) : Peripheral("Led"), pin(pin) {};

void Led::init() {
  Serial.begin(115200);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);  // Éteindre par défaut
}

void Led::low() {
  digitalWrite(pin, LOW);
}

void Led::high() {
  digitalWrite(pin, HIGH);
}
