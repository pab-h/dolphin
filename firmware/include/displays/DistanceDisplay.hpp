#ifndef DISTANCEDISPLAY_HEADER

#include "TM1637Display.h"
#include "meters/Hodometer.hpp"

#define DISTANCEDISPLAY_HEADER

class DistanceDisplay {
    private:

        int clockPin;
        int dioPin;

        TM1637Display* display;
        Hodometer* hodometer;

    public:

        DistanceDisplay(Hodometer* speedometer);
        ~DistanceDisplay();

        void setup();
        void update();

};



#endif