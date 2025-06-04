#include "ValveController.h"
#include <Arduino.h>

#define VALVE_PIN 32

void ValveController::begin() {
  pinMode(VALVE_PIN, OUTPUT);
  closeValve();
  Serial.println("ValveController initialized.");
}

void ValveController::update() {
  // Placeholder for logic or MQTT triggers
}

void ValveController::openValve() {
  digitalWrite(VALVE_PIN, HIGH);
  valveState = true;
  Serial.println("Valve opened.");
}

void ValveController::closeValve() {
  digitalWrite(VALVE_PIN, LOW);
  valveState = false;
  Serial.println("Valve closed.");
}
