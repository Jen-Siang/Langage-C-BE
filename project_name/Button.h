/*********************************************************************
 * @file  Button.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/**
  * @class Button
  * @brief Classe Button 
*/    
class Button
{
  public :
    /**
     * @fn Button();
     * @brief Constructeur par defaut
    */    
    Button();
    /**
     * @fn Button();
     * @brief Destructeur
    */    
    ~Button();    
    /**
     * @fn void run(void)
     * @brief Fonction de lancement du boutton
    */
    bool isPress(void);
};
#endif
