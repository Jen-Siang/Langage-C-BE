/*********************************************************************
 * @file  LCD.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef LCD_H_
#define LCD_H_

#include "rgb_lcd.h"

/**
  * @class LCD
  * @brief Classe LCD
*/    
class LCD
{
  private :
    rgb_lcd lcd;
    // Constantes pour les couleurs RGB
    const int colorR = 255; // Rouge
    const int colorG = 0;   // Vert
    const int colorB = 0;   // Bleu

  public :
    /**
     * @fn LCD();
     * @brief Constructeur par defaut
    */    
    LCD();
    /**
     * @fn LCD();
     * @brief Destructeur
    */    
    ~LCD();
    void init();
    void progChangeColor();
    void clear();
    void message(String message);
    void setCursor(int col, int lig);
};
#endif
