#include <Servo.h>
Servo motor;
void setup() {
  motor.attach(13);

}

void loop() {
  for(int i =180; i>=80; i--){
    motor.write(i);
    delay(10);
  }
  for(int i =80; i<=180; i++){
    motor.write(i);
    delay(10);
  }
  while(1);
}
