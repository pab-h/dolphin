#include <Arduino.h>

#include "setup.hpp"
#include "config.hpp"

#include "Speedometer.hpp"
#include "HallSensor.hpp"
#include "Hodometer.hpp"

Speedometer speedometer;
Hodometer hodometer;

HallSensor hallSensor;

void ISRHallSensorHitWrapper() {
    
    hodometer.ISRHallSensorHit();
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
    hodometer.setRadius(33);

}


void loop() {

    Serial.print("Velocidade = ");
    Serial.print(speedometer.getVelocity());
    Serial.print(" km/h ");

    Serial.print("Distância = ");
    Serial.print(hodometer.getDistance());
    Serial.print(" km\n");
    
    speedometer.resetTrigger();
    hodometer.resetTrigger();

}
