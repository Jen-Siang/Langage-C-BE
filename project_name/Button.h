#ifndef BUTTON_H_
#define BUTTON_H_

#include "Peripheral.h"

/**
 * @class Button
 * @brief Classe représentant un bouton
 */
class Button : public Peripheral {
private:
    int pin;  // Pin du bouton

public:
    Button(int pin);
    ~Button() {}

    void init() override;

    bool isPress();
};

#endif
