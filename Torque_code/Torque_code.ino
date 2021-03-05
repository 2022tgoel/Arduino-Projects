
#include <Servo.h>

Servo left;
Servo right;

void setup() { 
  left.attach(5); //left
  right.attach(6); //right

}

void loop() {
  left.write(90);
  right.write(90);
  delay(3000);
  left.write(180);
  right.write(0);

}
