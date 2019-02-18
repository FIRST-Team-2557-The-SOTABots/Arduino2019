//const int IR1 = A0;
//const int IR2 = A1;
//const int IR3 = A2;
#define IR1 A0
#define IR2 A1
#define IR3 A2


void setup() {
  // put your setup code here, to run once:
pinMode(IR1, OUTPUT);
pinMode(IR2, OUTPUT);
pinMode(IR3, OUTPUT);
delay(400);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IR1x;
  int IR2x;
  int IR3x;

  float volts1 = analogRead(IR1)*0.0048828125;  // value from sensor * (5/1024)
  int distance1 = 13*pow(volts1, -1); // worked out from datasheet graph
  delay(100); // slow down serial port 
  Serial.print("  distance1: ");
  Serial.print(distance1);
  Serial.print("   volts1: ");
  Serial.print(volts1);

  float volts2 = analogRead(IR2)*0.0048828125;  // value from sensor * (5/1024)
  int distance2 = 13*pow(volts2, -1); // worked out from datasheet graph
  delay(100); // slow down serial port 
  Serial.print("  distance2: ");
  Serial.print(distance2);
  Serial.print("   volts2: ");
  Serial.print(volts2);

  float volts3 = analogRead(IR3)*0.0048828125;  // value from sensor * (5/1024)
  int distance3 = 13*pow(volts3, -1); // worked out from datasheet graph
  delay(100); // slow down serial port 
  Serial.print("  distance3: ");
  Serial.print(distance3);
  Serial.print("   volts3: ");
  Serial.print(volts3);


  
  Serial.println(distance3);
}
