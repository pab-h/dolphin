#include <Arduino.h>
#include <EEPROM.h>

#include "setup.hpp"
#include "config.hpp"
#include "pins.hpp"

#include "sensors/HallSensor.hpp"
#include "sensors/PushButtonSensor.hpp"

#include "meters/Speedometer.hpp"
#include "meters/Hodometer.hpp"

#include "displays/SpeedDisplay.hpp"
#include "displays/DistanceDisplay.hpp"

HallSensor hallSensor;

Speedometer speedometer;
Hodometer hodometer;

SpeedDisplay speedDisplay(&speedometer);
DistanceDisplay distanceDisplay(&hodometer);

PushButtonSensor leftButton(LEFT_BUTTON_PIN);
PushButtonSensor rightButton(RIGHT_BUTTON_PIN);

bool lastConfigState = false;
bool configState     = false;

unsigned int radiusEEAddress = 0;
uint8_t radius               = 0; 


void ISRHallSensorHitWrapper() {
    
    hodometer.ISRHallSensorHit();
    speedometer.ISRHallSensorHit();

}

void toggleConfigMode() {

  lastConfigState = configState;
  configState = !configState;

  Serial.print("Modo de configuração = ");
  Serial.print(configState ? "ativado" : "desativado");
  Serial.print("\n");

  if (configState) {
    Serial.print("Tamanho do raio atual: R = ");
    Serial.print(radius);
    Serial.print("cm");
    Serial.print("\n");
  }

  if (lastConfigState && !configState) {

    Serial.print("Atualizando o tamanho do raio: R = ");
    Serial.print(radius);
    Serial.print("cm");
    Serial.print("\n");

    EEPROM.write(radiusEEAddress, radius);

    hodometer.setRadius(radius);
    speedometer.setRadius(radius);

  }

}

void onLeftClick() {

  if (!configState) {
    return;
  }
  
  radius++;

  Serial.print("Tamanho do raio atual: R = ");
  Serial.print(radius);
  Serial.print("cm");
  Serial.print("\n");

}

void onRightClick() {

  if (!configState) {
    return;
  }

  if (radius == 1) {
    return;
  }

  radius--;

  Serial.print("Tamanho do raio atual: R = ");
  Serial.print(radius);
  Serial.print("cm");
  Serial.print("\n");

}

void setup() {

  Serial.begin(9600);

  radius       = EEPROM.read(radiusEEAddress);

  Serial.print("Tamanho do raio atual [EEPROM]: R = ");
  Serial.print(radius);
  Serial.print("cm");
  Serial.print("\n");

  setupPins();

  distanceDisplay.setup();
  speedDisplay.setup();

  attachInterrupt(
      digitalPinToInterrupt(HALL_SENSOR_PIN),
      ISRHallSensorHitWrapper,
      RISING 
  );

  hodometer.setRadius(radius);
  speedometer.setRadius(radius);

  leftButton.addLongPressListener(toggleConfigMode);

  leftButton.addClickListener(onLeftClick);
  rightButton.addClickListener(onRightClick);

}


void loop() {

  leftButton.read();
  rightButton.read();

}
