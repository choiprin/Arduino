//===============로드셀 관련 선언============
#include "HX711.h"
HX711 scale;
const int LOADCELL_DOUT_PIN = D5; //로드셀 핀
const int LOADCELL_SCK_PIN = D6;  //로드셀 핀
String reading;
float calibration_factor = 34500;
unsigned long millisPrevious;
byte debounceInterval = 50;
//==============근접센서 관련 선언==============
const byte interruptPin = D2;
int buttonState= digitalRead(interruptPin) ,lastButtonState =1;
int counter;
//============================================

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();
}

void loop() {
  Loadcell();
}

void Loadcell(){
  buttonState = digitalRead(interruptPin);
  if ((buttonState == HIGH) && (lastButtonState == LOW)) {
    if (millis() - millisPrevious >= debounceInterval) {  
      scale.set_scale(calibration_factor);
      reading = scale.get_units(1);
      counter++;
      Serial.print("Loadcell : ");
      Serial.print(reading);
      Serial.print("kg");
      Serial.print("   ");
      Serial.println(counter);
    }
    millisPrevious = millis();
  }
  lastButtonState = buttonState;
}
