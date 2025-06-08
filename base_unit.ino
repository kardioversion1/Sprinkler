#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"

const char* mqtt_server = MQTT_SERVER;
const char* topic = "sprinkler/mastervalve";

#define VALVE_SENSOR_PIN 25

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32_BaseUnit")) {
      Serial.println("connected");
    } else {
      Serial.print("failed: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  pinMode(VALVE_SENSOR_PIN, INPUT);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
  static bool lastState = LOW;
  bool currentState = digitalRead(VALVE_SENSOR_PIN);
  if (currentState != lastState) {
    lastState = currentState;
    const char* msg = currentState == HIGH ? "ON" : "OFF";
    client.publish(topic, msg);
    Serial.print("Published valve status: ");
    Serial.println(msg);
  }
  delay(100);
}
