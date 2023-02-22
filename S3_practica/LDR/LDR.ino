#define PIN_LED 33
#define PIN_LDR 35

void setup() {
  Serial.begin(115200);

}

void loop() {
  int ldr_signal = analogRead(PIN_LDR);
  Serial.println(ldr_signal);
  delay(75);

}
