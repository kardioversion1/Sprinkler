#include "WiFiManager.h"
#include <WiFi.h>

const char* ssid = "Artemis";
const char* password = "Gocards1";

void WiFiManager::connect() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}
