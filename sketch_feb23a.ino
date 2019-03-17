//adds libraries
#include <VL53L1X.h>
#include <Wire.h>

//defines time of flight sensors
VL53L1X TOF1;
VL53L1X TOF2;

//assosiates IR names with analog pins
//#define sensor1 A0
//#define sensor2 A1
//#define sensor3 A2
//#define sensor4 A3
//#define sensor5 A4

void setup() {

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(15);
  Wire.begin();


  Serial.begin (9600);

  pinMode(4, INPUT);
  delay(150);
  TOF1.init(true);

  delay(100);
  TOF1.setAddress(0x28);

  pinMode(5, INPUT);
  delay(150);
  TOF2.init(true);

  delay(100);
  TOF2.setAddress(0x31);

  TOF1.setDistanceMode(VL53L1X::Long);
  TOF1.setMeasurementTimingBudget(50000);
  TOF1.startContinuous(50);
  TOF2.setDistanceMode(VL53L1X::Long);
  TOF2.setMeasurementTimingBudget(50000);
  TOF2.startContinuous(50);
  TOF1.setTimeout(100);
  TOF2.setTimeout(100);
  delay(150);

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

  if (Serial.peek() == 0)
  {
   Serial.end();
   delay(50);
   Serial.begin(9600);
   }
  
  //gets volts for IR
//  float volts1 = analogRead(sensor1)*0.0048828125;
//  float volts2 = analogRead(sensor2)*0.0048828125;
//  float volts3 = analogRead(sensor3)*0.0048828125;
//  float volts4 = analogRead(sensor4)*0.0048828125;
//  float volts5 = analogRead(sensor5)*0.0048828125;
  
  //conversion from voltage to distance
//  int distance1 = 13*pow(volts1, -1);
//  int distance2 = 13*pow(volts2, -1);
//  int distance3 = 13*pow(volts3, -1);
//  int distance4 = 13*pow(volts4, -1);
//  int distance5 = 13*pow(volts5, -1);
  
  //in mm
  Serial.print("ToFL");
  Serial.println(TOF1.read());
  Serial.flush();
  Serial.print("ToFR");
  Serial.println(TOF2.read());
  Serial.flush();

  //hopefully in mm
//  Serial.print("c");
//  Serial.println(distance1);
//  Serial.print("d");
//  Serial.println(distance2);
//  Serial.print("e");
//  Serial.println(distance3);
//  Serial.print("f");
//  Serial.println(distance4);
//  Serial.print("g");
//  Serial.println(distance5);
}
