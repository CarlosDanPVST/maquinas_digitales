#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;

void setup() {
  bmp.begin(0x76);
  Serial.begin(115200);

}

void loop() {
  char payload[80];

  sprintf(payload, "%.2f,%.2f",
    bmp.readTemperature(),
    bmp.readPressure() / 1000);
  Serial.println(payload);

  delay(200);

}
