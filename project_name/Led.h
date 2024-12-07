#ifndef LED_H_
#define LED_H_

#include "Peripheral.h"

/**
 * @class Led
 * @brief Classe représentant une LED
 */
class Led : public Peripheral {
private:
    int pin;  // Pin de la LED

public:
    Led(int pin);
    ~Led() {};

    void init() override;

    void high();

    void low();
};

#endif
