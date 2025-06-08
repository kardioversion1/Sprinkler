#include "WiFiManager.h"
#include <WiFi.h>
#include "config.h"

void WiFiManager::connect() {
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(true); // enable modem sleep for lower power consumption
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}
