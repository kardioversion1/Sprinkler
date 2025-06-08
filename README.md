# Sprinkler
A Master Valve, environmental monitor, and sprinkler remote control

## Configuration

Network credentials and the MQTT broker address are stored in `config.h`.  
Edit the values for `WIFI_SSID`, `WIFI_PASSWORD` and `MQTT_SERVER` before
compiling the project:

```cpp
#define WIFI_SSID "your_wifi_name"
#define WIFI_PASSWORD "your_wifi_password"
#define MQTT_SERVER "mqtt_broker_ip"
```
