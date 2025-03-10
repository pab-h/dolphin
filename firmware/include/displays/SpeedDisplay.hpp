#ifndef SPEEDDISPLAY_HEADER

#include "TM1637Display.h"
#include "meters/Speedometer.hpp"

#define SPEEDDISPLAY_HEADER

class SpeedDisplay {
    private:

        int clockPin;
        int dioPin;

        TM1637Display* display;
        Speedometer* speedometer;

    public:

        SpeedDisplay(Speedometer* speedometer);
        ~SpeedDisplay();

        void setup();
        void update();

};


#endif