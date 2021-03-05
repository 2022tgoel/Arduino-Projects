#include <Servo.h>
Servo motorL; 
Servo motorR;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  motorL.attach(5); //stop val = 80
  motorR.attach(6); //stop val = 90
  Serial.begin(9600);
}

void loop() {
  float x = float(analogRead(A0)) *255.0/1023.0;
  float y = float(analogRead(A1)) *255.0/1023.0;
  Serial.print(x);
  Serial.print("  ");
  Serial.println(y);
  motorL.write(x);
  motorR.write(y);
  delay(12000);
  motorL.write(90);
  motorR.write(90);
  while(1); 
}
