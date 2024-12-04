/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Button.h"
#include "Led.h"
#include "LCD.h"
#include "rotaryAngleSensor.h"
#include "snake.h"
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
    LCD myLCD;
    myLCD.init();
}


void Application::run(void)
{
//    Button myButton;
//    Led myLed;
//    LCD myLCD;
//
//    bool buttonPressedLast = false;
//    bool actionState = false;
//
//    while (true){
//      bool buttonPressedCurrent = myButton.isPress();
//
//      if(buttonPressedCurrent && (not buttonPressedLast)){
//        actionState = !actionState;
//
//        if(actionState){
//          myLed.high();
//          myLCD.clear();
//          myLCD.message("Button pressed");
//    //      lcd.setCursor(0, 1); // Colonne 0, ligne 1
//    //      lcd.print(":)");
//          myLCD.progChangeColor();
//          
//          while(true){
//            rotaryAngleSensor myRotaryAngleSensor;
//            myRotaryAngleSensor.run();
//            if(myButton.isPress()){
//              break;
//            }
//          }
//        }
//        else{
//          myLed.low();
//          myLCD.clear();
//          myLCD.message("not pressed");
//      //  lcd.setCursor(0, 1); // Colonne 0, ligne 1
//      //  lcd.print(":(");
//        }
//      }
//
//      buttonPressedLast = buttonPressedCurrent;
//      delay(50);
//    }

    LCD myLCD;
    Button startButton;
    Led myLed;
    rotaryAngleSensor rotationSensor;

    // Afficher "Press to Start" sur l'écran LCD
    myLCD.clear();
    myLCD.message("Press button");

    // Attendre que le bouton soit pressé
    while (!startButton.isPress()) {
        delay(500); // Attendre que le bouton soit pressé
    }
    Serial.println("start_game");
    delay(500);

//    myLCD.clear();
//    myLCD.message("Game Over!");
//    myLed.high();
//    delay(2000);
//    myLed.low();
}
