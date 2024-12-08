#ifndef PERIPHERAL_H_
#define PERIPHERAL_H_

#include <Arduino.h>
#include <string>

/**
 * @class Peripheral
 * @brief Classe de base pour tous les périphériques
 */
class Peripheral {
protected:
    String name;  // Nom ou identifiant du périphérique
    bool isActive; // État activé/désactivé

public:
    Peripheral(String name) : name(name), isActive(false) {}
    virtual ~Peripheral() {}

    virtual void init() = 0; // Méthode virtuelle pure pour l'initialisation
};

#endif
