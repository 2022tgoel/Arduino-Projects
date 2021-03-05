//Name: Tarushii Goel
//Objective: Traverse the maze challenge.

#include <Servo.h>

//bumper switches pins
#define sensor1 9
#define sensor2 10

//ultrasonic pins
const int trigPin = 2;
const int echoPin = 3;

//Servos
Servo left;
Servo right;
Servo frontServo;

void setup() {
  //attach servos to pin #
  left.attach(5); //left
  right.attach(6); //right
  frontServo.attach(11);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
 
}

//left motor stop value = 90, right motor stop value = 88
void loop() {
  left.write(90);
  right.write(89);
  frontServo.write(120);
  delay(3000);
  //functions to do various parts of the maze
  goToBall(left, right);
  getBall(frontServo);
  goToWallWithUltraAdjustment(left, right);
  turnRight(left, right);
  goToWallWithUltraAdjustment(left, right);
  turnRight(left, right);
  goToWall(left, right);
  turnLeft(left, right);
  goToWall(left, right);
  turnRight(left, right);
  goToWallWithUltraAdjustment(left, right);
  turnRight(left, right);
  goToWallWithUltraAdjustment(left, right);
  turnRight(left, right);
  goToWall(left, right);
  turnLeft(left, right);
  goToWall(left, right);
  left.write(0);
  right.write(180);
  delay(400);
  turnLeft(left, right);
  goToWall(left, right);
  turnRight(left, right);
  goToWall(left, right);
  frontServo.detach();
  left.detach();
  right.detach();
  while(1){
    delay(1);
  }
}

void getBall(Servo motor){
  delay(200);
  for(int i =120; i>=90; i--){
    motor.write(i);
    delay(5);
  }
  
}
void turnLeft(Servo motorLeft, Servo motorRight){
  motorLeft.write(180);
  motorRight.write(180);
  delay(2700);
  motorLeft.write(90);
  motorRight.write(89);
}
void turnRight(Servo motorLeft, Servo motorRight){
  motorLeft.write(0);
  motorRight.write(0);
  delay(2700);
  motorLeft.write(90);
  motorRight.write(89);
}
void goToBall(Servo motorLeft, Servo motorRight){
  motorLeft.write(160);
  motorRight.write(20);
  delay(3000);
  //slows down to prevent pushing the ball out of the target area
  motorLeft.write(105);
  motorRight.write(70);
  delay(2800); //from start wheel point on contact to end 
  motorLeft.write(90);
  motorRight.write(89);
}
void goToWall(Servo motorLeft, Servo motorRight){
  motorLeft.write(180);
  motorRight.write(0);
  while(digitalRead(sensor1)==0 && digitalRead(sensor2)==0){ 
    delayMicroseconds(5);
  }
  motorLeft.write(0);
  motorRight.write(180);
  delay(500);
  motorLeft.write(90);
  motorRight.write(89);
}
void goToWallWithUltraAdjustment(Servo motorLeft, Servo motorRight){
  motorLeft.write(180);
  motorRight.write(0);
  int c=0;
  while(digitalRead(sensor1)==0 && digitalRead(sensor2)==0){ 
    if (c==99){
      long r = takeUltrasonicReading();
      Serial.println(r);
      if (r>13){
        continue;
      }
      //making slight turns based on the ultrasonic reading
      if (r<5){
        motorLeft.write(90);
        motorRight.write(0);
        Serial.println("left");
        delay(200);
        motorLeft.write(180);
        motorRight.write(0);
      }
      else if(r>8){
        motorLeft.write(180);
        motorRight.write(88);
        Serial.println("right");
        delay(200);
        motorLeft.write(180);
        motorRight.write(0);
      }
    }
    c=(c+1)%100;
    delay(1);
  }
  motorLeft.write(0);
  motorRight.write(180);
  delay(500);
  motorLeft.write(90);
  motorRight.write(89);
}
long takeUltrasonicReading(){
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  return distance;

}
