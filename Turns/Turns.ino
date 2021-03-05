#include <Servo.h>
Servo motorL; 
Servo motorR;

void setup() {
  motorL.attach(3); //stop val = 80
  motorR.attach(4); //stop val = 90
  Serial.begin(9600);
}

void loop() {
  motorL.write(90);
  motorR.write(90);
  motorL.write(255);
  motorR.write(255);
  delay(3000);
  motorL.write(0);
  motorR.write(90);
  delay(5000);
  motorL.detach();
  motorR.detach();
  while(1);
}
