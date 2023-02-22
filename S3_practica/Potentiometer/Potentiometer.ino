#define PIN_LED 33
#define PIN_POTENTIOMETER 32

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POTENTIOMETER, INPUT);
  Serial.begin(115200);

}

void loop() {
  int potentiometer_signal = analogRead(PIN_POTENTIOMETER);

  if(potentiometer_signal > 2700){
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }

  Serial.println(potentiometer_signal);
  delay(75);

}
