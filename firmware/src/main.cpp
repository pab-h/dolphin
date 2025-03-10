#include <Arduino.h>

#include "setup.hpp"
#include "config.hpp"
#include "pins.hpp"

#include "sensors/HallSensor.hpp"

#include "meters/Speedometer.hpp"
#include "meters/Hodometer.hpp"

#include "displays/SpeedDisplay.hpp"
#include "displays/DistanceDisplay.hpp"

HallSensor hallSensor;

Speedometer speedometer;
Hodometer hodometer;

SpeedDisplay speedDisplay(&speedometer);
DistanceDisplay distanceDisplay(&hodometer);

void ISRHallSensorHitWrapper() {
    
    hodometer.ISRHallSensorHit();
    speedometer.ISRHallSensorHit();

}

void setup() {

    setupPins();

    distanceDisplay.setup();
    speedDisplay.setup();

    attachInterrupt(
        digitalPinToInterrupt(HALL_SENSOR_PIN),
        ISRHallSensorHitWrapper,
        RISING 
    );

    hodometer.setRadius(33);
    speedometer.setRadius(33);

}


void loop() {

    delay(500);

    speedDisplay.update();
    distanceDisplay.update();

    speedometer.resetTrigger();
    hodometer.resetTrigger();

}
