#include <Arduino.h>

#include "setup.hpp"
#include "Speedometer.hpp"
#include "HallSensor.hpp"
#include "config.hpp"

Speedometer speedometer;
HallSensor hallSensor;

void ISRHallSensorHitWrapper() {
    speedometer.ISRHallSensorHit();
}

void setup() {
    Serial.begin(9600);

    setupPins();

    attachInterrupt(
        digitalPinToInterrupt(HALL_SENSOR_PIN),
        ISRHallSensorHitWrapper,
        RISING 
    );

    speedometer.setRadius(33);

}


void loop() {

    Serial.print("Velocity = ");
    Serial.println(speedometer.getVelocity(), 2);
    
    speedometer.updateVelocity();
    speedometer.resetTrigger();

}
