#include "HX711.h"
 
#define calibration_factor 34500.0
#define LOADCELL_DOUT_PIN D5
#define LOADCELL_SCK_PIN D6
int nValueCount = 10;   //n으로 두면 n개의 값을 측정
float fValue[10];       //n개의 값들을 담을 배열
 
HX711 scale;

void setup() 
{
  Serial.begin(9600);
  Serial.println("HX711 kg demo");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();
}
 
void loop() 
{
  Serial.print("Reading: ");
  float fValueTemp = 0.0;
  float fValueSum = 0.0;
  fValueTemp = scale.get_units();
  fValueSum = fValueTemp; 
  int i;
  for(i = 0; i < nValueCount; i = i + 1)
  {
    if(i > 0)
    {
      fValueSum = fValueSum + fValue[i];
      fValue[i - 1] = fValue[i];
    }
  }
  fValue[nValueCount - 1] = fValueTemp;
  Serial.print((fValueSum / nValueCount), 1);
  Serial.print(" kg");
  Serial.println();
}
