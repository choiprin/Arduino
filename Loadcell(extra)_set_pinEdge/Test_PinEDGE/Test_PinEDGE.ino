int buttonState = 1;
int lastButtonState = 1;

unsigned long millisPrevious;
byte debounceInterval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(D2, INPUT_PULLUP);
}

void loop() {
  
  buttonState = digitalRead(D2);
  if ((buttonState == HIGH) && (lastButtonState == LOW)) {
    delay(30);
    if(lastButtonState == LOW)
    if (millis() - millisPrevious >= debounceInterval) {  // if debounce interval expired
      Serial.println("There was a falling edge on pin 11");
    }
    millisPrevious = millis();
  }
  lastButtonState = buttonState;

}
