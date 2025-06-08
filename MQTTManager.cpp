#include "MQTTManager.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include "ValveController.h"
#include "config.h"

extern ValveController valve;

WiFiClient espClient;
PubSubClient client(espClient);

const char* mqtt_server = MQTT_SERVER;
const char* mqtt_topic = "sprinkler/mastervalve";

void callback(char* receivedTopic, byte* payload, unsigned int length) {
  String msg = "";
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.print("MQTT message received: ");
  Serial.println(msg);
  if (msg == "ON") valve.openValve();
  else if (msg == "OFF") valve.closeValve();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32_MasterValve")) {
      Serial.println("connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void MQTTManager::begin() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void MQTTManager::loop() {
  if (!client.connected()) reconnect();
  client.loop();
}
