/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Button.h"
#include "Led.h"
#include "LCD.h"
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
    Button myButton;
    Led myLed;
    LCD myLCD;
    if(myButton.isPress()){
      myLed.high();
      myLCD.clear();
      myLCD.message("Button pressed");
//      lcd.print("Button pressed");
//      lcd.setCursor(0, 1); // Colonne 0, ligne 1
//      lcd.print(":)");

      // Change la couleur du rétroéclairage progressivement
      myLCD.progChangeColor();
    }
    else{
      myLed.low();
      myLCD.clear();
      myLCD.message("not pressed");
//      lcd.print("not pressed");
//      lcd.setCursor(0, 1); // Colonne 0, ligne 1
//      lcd.print(":(");
      delay(50);
    }  
}
