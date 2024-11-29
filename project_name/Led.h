/*********************************************************************
 * @file  Led.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef LED_H_
#define LED_H_

/**
  * @class Led
  * @brief Classe Led 
*/    
class Led
{
  public :
    /**
     * @fn Led();
     * @brief Constructeur par defaut
    */    
    Led();
    /**
     * @fn Led();
     * @brief Destructeur
    */    
    ~Led();    
    /**
     * @fn void run(void)
     * @brief Fonction de lancement pour mettre la led à l'état bas
    */
    void low(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement pour mettre la led  à l'état haut
    */
    void high(void);
};
#endif
