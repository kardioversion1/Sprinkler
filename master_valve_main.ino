#include "ValveController.h"
#include "MQTTManager.h"
#include "WiFiManager.h"
#include "Watchdog.h"

ValveController valve;
MQTTManager mqtt;
Watchdog watchdog;

void setup() {
  Serial.begin(115200);
  WiFiManager::connect();
  valve.begin();
  mqtt.begin();
  watchdog.begin();
}

void loop() {
  mqtt.loop();
  valve.update();
  watchdog.feed();
}
