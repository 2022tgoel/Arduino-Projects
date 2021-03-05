#include <Servo.h>


//Servos
Servo left;
Servo right;

void setup() {
  //attach servos to pin #
  left.attach(5); //left
  right.attach(6); //right
  left.write(90);
  right.write(88);
  delay(3000);
  // put your setup code here, to run once:

}

void loop() {
  left.write(180);
  right.write(0);
  // put your main code here, to run repeatedly:

}
