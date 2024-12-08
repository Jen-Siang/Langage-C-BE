/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
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


Application::Application()
{
  ; 
}
  
Application::~Application()
{
  ;
}  

void Application::init(void)
{
    Serial.begin(115200);   // Ouvre le port série à 115200 bauds
    Serial.println("Initialisation réussie");
}


void Application::run(void)
{
    LCD myLCD;
    Button startButton(D8);  // Bouton sur D8
    Led myLed(D5);           // LED sur D5
    rotaryAngleSensor rotationSensor(A0);  // Capteur sur A0

    myLCD.init();
    startButton.init();
    myLed.init();
    rotationSensor.init();
    
    try{
      // Attendre que le bouton soit pressé
      while (!startButton.isPress()) {
        myLCD.clear();
        myLCD.message("Press button");
        myLCD.setCursor(0, 1);
        myLCD.message("to start");
        delay(500); // Attendre que le bouton soit pressé
      }
  
      Serial.println("start_game");
      delay(500);
  
      while(true){
        myLed.high();
        
        if (Serial.available() < 0) {  // Vérifiez si le port série est indisponible
          throw PeripheralException("Serial port unavailable");
        }
        
        if (Serial.available() > 0) {
          String message = Serial.readStringUntil('\n');  // Lire jusqu'à la fin de ligne
          //message = message.substring(1); // Enleve le premier caractère
          //Serial.println(message);
          
          if (message.startsWith("score:")) {
              String score = message.substring(6);  // Extraire la valeur du score
              delay(500);
              myLCD.clear();
              myLCD.message("Game started");
              myLCD.setCursor(0, 1);  // Ligne 2
              myLCD.message("Score:");
              myLCD.setCursor(7, 1);  // Afficher le score à droite
              myLCD.message(score);
          }
          
          if (message.startsWith("game_over")) {
            myLed.low();
            myLCD.clear();
            myLCD.message("Game Over");
            while (!startButton.isPress()) {
              delay(500);
            }
            break;  
          }   
        }
        
        rotationSensor.run();
      }
    } catch (const PeripheralException& e) {
        Serial.print("Erreur : ");
    }
}
