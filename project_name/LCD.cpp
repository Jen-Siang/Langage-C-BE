/*********************************************************************
 * @file  LCD.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "LCD.h"
#include "rgb_lcd.h"
#include <Arduino.h>

LCD::LCD(){
  Serial.begin(115200);
  lcd.begin(16, 2); // Écran 16 colonnes, 2 lignes
  lcd.clear();
}

LCD::~LCD(){;}

void LCD::init(){
  Serial.begin(115200);
  // Initialisation de l'écran LCD
  lcd.begin(16, 2); // Écran 16 colonnes, 2 lignes
  // Définit la couleur du rétroéclairage
  lcd.setRGB(colorR, colorG, colorB);
  // Affiche un message
  lcd.print("Initialisation");
  delay(2000); // Attendre 2 secondes
  // Efface l'écran
  lcd.clear();
}
void LCD::progChangeColor(){
  for (int i = 0; i <= 255; i++) {
     lcd.setRGB(i, 255 - i, i / 2);
     delay(10);
  }
    
  for (int i = 255; i >= 0; i--) {
     lcd.setRGB(i, 255 - i, i / 2);
     delay(10);
  }
}

void LCD::clear(){
  lcd.clear();
  lcd.setCursor(0, 0); // Colonne 0, ligne 0
}

void LCD::message(String message){
  lcd.print(message);
 }
