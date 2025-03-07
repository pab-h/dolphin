#include <Arduino.h>

#include "pins.hpp"
#include "setup.hpp"

void setupPins() {

    pinMode(LEFT_BUTTON_PIN, INPUT);
    pinMode(RIGHT_BUTTON_PIN, INPUT);

    pinMode(DISPLAY_DISTANCE_CLOCK_PIN, OUTPUT);
    pinMode(DISPLAY_DISTANCE_DATA_PIN, OUTPUT);

    pinMode(DISPLAY_VELOCITY_CLOCK_PIN, OUTPUT);
    pinMode(DISPLAY_VELOCITY_DATA_PIN, OUTPUT);

    pinMode(HALL_SENSOR_PIN, INPUT);

}


