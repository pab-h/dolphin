#ifndef SPEED_DISPLAY_HEADER

#include "TM1637Display.h"
#include "meters/Speedometer.hpp"

#define SPEED_DISPLAY_HEADER

class SpeedDisplay {
    private:

        uint8_t clockPin;
        uint8_t dioPin;

        TM1637Display* display;
        Speedometer* speedometer;

    public:

        SpeedDisplay(Speedometer* speedometer);
        ~SpeedDisplay();

        void setup();
        void update();

};


#endif