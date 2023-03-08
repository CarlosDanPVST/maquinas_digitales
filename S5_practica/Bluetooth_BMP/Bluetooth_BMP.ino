#include "Adafruit_BMP280.h"

#define LED_PIN 33
#define LDR_PIN 35

Adafruit_BMP280 bmp;
char recorder [80];

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;


void setup() {

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Gecko_Carlos");
  bmp.begin(0x76);
  Serial.println("¡Bluetooth listo!");
}

void loop() {

  sprintf(recorder, "%6.2f, %3.2f, %d",
    bmp.readPressure(),
    bmp.readTemperature(),
    analogRead(LDR_PIN)
  );

  digitalWrite(LED_PIN, HIGH);
  Serial.println("Transmitiendo");
  SerialBT.println(recorder);
  delay(1000);
  digitalWrite(LED_PIN, LOW);

  delay(1000);

}
