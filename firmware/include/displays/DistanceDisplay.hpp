#ifndef DISTANCE_DISPLAY_HEADER

#include "TM1637Display.h"
#include "meters/Hodometer.hpp"

#define DISTANCE_DISPLAY_HEADER

class DistanceDisplay {
    private:

        uint8_t clockPin;
        uint8_t dioPin;

        TM1637Display* display;
        Hodometer* hodometer;

    public:

        DistanceDisplay(Hodometer* hodometer);
        ~DistanceDisplay();

        void setup();
        void update();

};



#endif