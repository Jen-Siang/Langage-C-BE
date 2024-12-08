/*********************************************************************
 * @file  LCD.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "LCD.h"
#include "rgb_lcd.h"
#include <Arduino.h>

LCD::LCD() : Peripheral("LCD") {};

void LCD::init() {
  Serial.begin(115200);
  lcd.begin(16, 2); // LCD 16 colonnes, 2 lignes
  lcd.setRGB(colorR, colorG, colorB); // Couleur par défaut
  lcd.print("Initialisation");
  delay(2000); // Attendre 2 secondes
  lcd.clear(); // Efface l'écran
}

void LCD::clear() {
  lcd.clear();
  lcd.setCursor(0, 0); // Colonne 0, ligne 0
}

void LCD::message(const String message) {
  lcd.print(message);
}

void LCD::setCursor(int col, int row){
  lcd.setCursor(col, row);
}

void LCD::progChangeColor() {
  for (int i = 0; i <= 255; i++) {
     lcd.setRGB(i, 255 - i, i / 2);
     delay(10);
  }
    
  for (int i = 255; i >= 0; i--) {
     lcd.setRGB(i, 255 - i, i / 2);
     delay(10);
  }
}

LCD& LCD::operator<<(const String& message) {
    this->message(message);
    return *this;
}
