/*
  Blink

  Turns on and off two light emitting diodes (LED) connected to a digital pin,
  with using the delay() function.
*/

//Used here to set count:
int count =  0;
void setup() {
  // set the digital pins as output:
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, INPUT);
  
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

    int i=1;
    while (digitalRead(13) == 0 && i<=20){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      delay(200);
      digitalWrite(5, LOW);
      digitalWrite(6,  HIGH);
      delay(200);
      count ++;
      Serial.println(count);
      i+=2;
    }
    Serial.print("YAY!!!!!");
    while(1);
 }





