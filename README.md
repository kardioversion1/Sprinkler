# Sprinkler

This project contains Arduino sketches for controlling a master irrigation valve and a base unit that reports valve status over MQTT. It runs on the ESP32 platform and communicates with a Wi-Fi network and MQTT broker.

## Hardware
- ESP32 development board
- Relay or MOSFET to drive the valve (connected to GPIO 32 by default)
- Valve position sensor for the base unit (connected to GPIO 25)

## Setup
1. Copy `config.h.example` to `config.h` and fill in your Wi-Fi credentials and MQTT broker address.
2. Open `master_valve_main.ino` (or `base_unit.ino`) in the Arduino IDE or PlatformIO.
3. Install the required libraries:
   - `WiFi` (built into ESP32 package)
   - `PubSubClient`
4. Select the appropriate ESP32 board and compile/upload the sketch.

## Power Saving
The Wi-Fi manager enables modem sleep mode to reduce power consumption while maintaining network connectivity.

## Files
- `master_valve_main.ino` – main sketch controlling the valve
- `base_unit.ino` – publishes valve sensor status
- `ValveController.*` – controls the valve hardware
- `MQTTManager.*` – handles MQTT messages
- `WiFiManager.*` – connects to Wi-Fi
- `Watchdog.*` – feeds the watchdog timer

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
