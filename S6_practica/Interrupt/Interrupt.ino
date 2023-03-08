#define PIN_BUTTON 34
int numBotPres = 0;
// Unsigned 32-bit integer
uint32_t lastMillis = 0;

// if block to deal with "debouncing" when pressing button
void IRAM_ATTR isrButton(){
  if(millis() - lastMillis > 10){
    numBotPres += 1;
    lastMillis = millis();
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT);

  attachInterrupt(PIN_BUTTON, isrButton, RISING);

}

void loop() {
  Serial.printf("El botón se ha presionado %u veces\n", numBotPres);

}
