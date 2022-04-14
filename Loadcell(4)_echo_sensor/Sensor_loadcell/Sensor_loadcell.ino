//===============로드셀 관련 선언============
#include "HX711.h"
HX711 scale;
const int LOADCELL_DOUT_PIN = D5; //로드셀 핀
const int LOADCELL_SCK_PIN = D6;  //로드셀 핀
const byte interruptPin = D2;      // 입력핀(스위치)
long loadcellcounter = 0;        //계측값,계측횟수
String reading;
float calibration_factor = 34500;
int buttonState= digitalRead(interruptPin) ,lastButtonState =1;
unsigned long millisPrevious;
byte debounceInterval = 50;
//=========================================
//============초음파센서 관련 선언===========
int trigPin = D1;
int echoPin = D7;
float distance,duration;
//=========================================

void Measure(){
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (float)duration*0.017;
  Serial.print("DIstance:");
  Serial.print(distance);
  Serial.print("cm\n");

  if(distance<5){
  buttonState = FALLING;
  if (buttonState == FALLING) {
    if (millis() - millisPrevious >= debounceInterval) {  
      loadcellcounter++;
      scale.set_scale(calibration_factor);
      reading = scale.get_units(1);
      Serial.print("Loadcell : ");
      Serial.print(reading+"kg    ");
      Serial.println(loadcellcounter);
      Serial.println("===================");
    }
    millisPrevious = millis();
  }
  lastButtonState = buttonState;
  }
}

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Measure();
}

/*void Loadcell(){
  buttonState = digitalRead(interruptPin);
  if ((buttonState == HIGH) && (lastButtonState == LOW)) {
    if (millis() - millisPrevious >= debounceInterval) {  
      scale.set_scale(calibration_factor);
      reading = scale.get_units(1);
      Serial.print("Loadcell : ");
      Serial.println(reading);
    }
    millisPrevious = millis();
  }
  lastButtonState = buttonState;
}*/
