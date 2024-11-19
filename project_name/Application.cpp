/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Arduino.h>
#include "rgb_lcd.h"

#define LED_PIN D5
#define BUTTON_PIN D8

// Crée un objet pour l'écran LCD
rgb_lcd lcd;

// Constantes pour les couleurs RGB
const int colorR = 255; // Rouge
const int colorG = 0;   // Vert
const int colorB = 0;   // Bleu

Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
    pinMode(LED_PIN, OUTPUT);            // Configure la broche de la LED
    pinMode(BUTTON_PIN, INPUT);
    
    Serial.begin(115200);   // Ouvre le port série à 115200 bauds
    
     // Initialisation de l'écran LCD
    lcd.begin(16, 2); // Écran 16 colonnes, 2 lignes
    // Définit la couleur du rétroéclairage
    lcd.setRGB(colorR, colorG, colorB);
    // Affiche un message
    lcd.print("Initialisation");
    delay(2000); // Attendre 2 secondes
    // Efface l'écran
    lcd.clear();

    Serial.println("Initialisation réussie");
    ;
}


void Application::run(void)
{
    int buttonState = digitalRead(BUTTON_PIN);
    if(buttonState == LOW){
      digitalWrite(LED_PIN, LOW);
      Serial.println("Button not pressed");
      lcd.clear();
      lcd.setCursor(0, 0); // Colonne 0, ligne 0
      lcd.print("not pressed");
      lcd.setCursor(0, 1); // Colonne 0, ligne 1
      lcd.print(":(");
      delay(50);
    }
    else{
      digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("Button pressed");
      lcd.clear();
      lcd.setCursor(0, 0); // Colonne 0, ligne 0
      lcd.print("Button pressed");
      lcd.setCursor(0, 1); // Colonne 0, ligne 1
      lcd.print(":)");

      // Change la couleur du rétroéclairage progressivement
      for (int i = 0; i <= 255; i++) {
        lcd.setRGB(i, 255 - i, i / 2);
        delay(10);
      }
    
      for (int i = 255; i >= 0; i--) {
        lcd.setRGB(i, 255 - i, i / 2);
        delay(10);
      }
    }
  
}
