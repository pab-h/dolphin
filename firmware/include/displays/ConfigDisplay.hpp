#ifndef CONFIG_DISPLAY_HEADER

#include <TM1637Display.h>

#define CONFIG_DISPLAY_HEADER

class ConfigDisplay {
    private:

        uint8_t* radius;
        
        uint8_t topClockPin;
        uint8_t topDioPin;

        uint8_t bottomClockPin;
        uint8_t bottomDioPin;

        TM1637Display* topDisplay;
        TM1637Display* bottomDisplay;

        const uint8_t FLATLINE[4] = {
            SEG_G, // -
            SEG_G, // -
            SEG_G, // -
            SEG_G  // -
        };
        const uint8_t DONE[4] = {
            SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,         // d
            SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, // O
            SEG_C | SEG_E | SEG_G,                         // n
            SEG_A | SEG_D | SEG_E | SEG_F | SEG_G          // E
        };     

    public:

        ConfigDisplay(uint8_t* radius);
        ~ConfigDisplay();

        void done();

        void setup();
        void update();

};


#endif