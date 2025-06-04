#include "Watchdog.h"
#include <esp_task_wdt.h>

#define WDT_TIMEOUT 10

void Watchdog::begin() {
  esp_task_wdt_init(WDT_TIMEOUT, true);
  esp_task_wdt_add(NULL);
  Serial.println("Watchdog initialized.");
}

void Watchdog::feed() {
  esp_task_wdt_reset();
}
