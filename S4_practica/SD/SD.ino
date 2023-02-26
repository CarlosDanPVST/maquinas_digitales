#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "Adafruit_BMP280.h"

#define LED_PIN 33
#define LDR_PIN 35


File readings;
Adafruit_BMP280 bmp;
char recorder [80];

void setup() {

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);

  if(SD.begin()){
    Serial.println("Card mounted failed");
    return;
  }


}

void loop() {

  sprintf(recorder, "%6.2f, %3.2f, %d",
    bmp.readPressure(),
    bmp.readTemperature(),
    analogRead(LDR_PIN)
  );

  digitalWrite(LED_PIN, HIGH);
    readings = SD.open("/lecturas_sensor.csv", FILE_APPEND);
    readings.println(recorder);
    readings.close();
    Serial.println("Imprimiendo");
    delay(1000);
  digitalWrite(LED_PIN, LOW);

  delay(1000);

}
