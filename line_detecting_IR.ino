#include <Wire.h>
int IR_lineFollowerPin[6] = {A0, A1, A2, A3, A4, A5};
int IR_line_min_threshold[6] = {};//numbers that are min for line sensing 1
// variable to store the value coming from the sensors.
//double  IR_sensorValue[8]
double  IR_lineValue[6];
bool    lineBool;
bool    sensorBool;

// Delay
int delay_ms = 500;

// Declare your variables.
String  sensor;
int     location;
int     measurement;

// Declare your thresholds.
int sensorMin = -1;
int lineMin = 1000;


void setup() {

  Wire.begin();
   for (int i = 0; i < 6; i++){
    pinMode(IR_lineFollowerPin[i], INPUT);
   }
  // Set Booleans to False
//  lineBool = false;
//  sensorBool = false;

  Serial.begin (9600);

  byte count = 0;
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      count++;
    }
  }
}

void loop() {
  
      for (int i = 0; i < 6; i++){
      IR_lineValue[i] = analogRead(IR_lineFollowerPin[i]);
    };
    for( int a = 0; a < 6; a = a + 1 ){
      sensor = "Line";
      location = a;
      measurement = IR_lineValue[a];
      if (measurement < IR_line_min_threshold[a]){
        lineBool = true;
      } else {
        lineBool = false;
      }
      Serial.print(sensor);
      Serial.print(location);
      Serial.print(":");
//      Serial.print("\t:\t");
      Serial.println(measurement);
    }
//    Serial.println("\n\n");
//    delay(500);
}
//
