#ifndef LCD_H_
#define LCD_H_

#include "Peripheral.h"
#include "rgb_lcd.h"

/**
 * @class LCD
 * @brief Classe représentant un écran LCD
 */
class LCD : public Peripheral {
private:
    rgb_lcd lcd;

    // Constantes pour les couleurs RGB
    const int colorR = 255;
    const int colorG = 0;
    const int colorB = 0;

public:
    LCD();
    ~LCD() {};

    void init() override;

    void clear();

    void message(const String message);

    void setCursor(int col, int row);

    void progChangeColor();

    LCD& operator<<(const String& message);
};

#endif
