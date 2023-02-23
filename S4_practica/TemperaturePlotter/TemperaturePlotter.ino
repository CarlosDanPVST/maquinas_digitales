#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;

void setup() {
  bmp.begin(0x76);
  Serial.begin(115200);

}

void loop() {
  Serial.println(bmp.readTemperature());
  delay(200);

}
