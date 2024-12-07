#ifndef ROTARY_ANGLE_SENSOR_H_
#define ROTARY_ANGLE_SENSOR_H_

#include "Peripheral.h"

/**
 * @class rotaryAngleSensor
 * @brief Classe représentant un capteur de rotation
 */
class rotaryAngleSensor : public Peripheral {
private:
    int pin;  // Pin analogique du capteur

public:
    rotaryAngleSensor(int pin);
    ~rotaryAngleSensor(){};

    void init() override;

    void run();
};

#endif
