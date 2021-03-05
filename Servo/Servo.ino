#include <Servo.h>
Servo motorL;
Servo motorR;

void setup() {
  motorL.attach(4); //stop val = 80
  motorR.attach(5); //stop val = 90
  Serial.begin(9600);
}

void loop() {
  motorL.write(150);
  motorR.write(25); 
  delay(2000);
  motorL.write(80);
  motorR.write(90);
  delay(100);
  motorL.write(10);
  motorR.write(160);
  delay(2000);
  motorL.write(80);
  motorR.write(90);
  delay(100);
  while(1);
  //motorR.write(90);
  //delay(300);
  // put your main code here, to run repeatedly:

}
