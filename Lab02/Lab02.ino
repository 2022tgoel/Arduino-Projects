/*
  For Loop Iteration

  Demonstrates the use of a for() loop.
  Lights multiple LEDs in sequence, then in reverse.

  The circuit:
  - LEDs from pins 2 through 7 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ForLoop
*/

void setup() {
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(13, INPUT);
  }
}

void loop() {
  int timer = 100;// The higher the number, the slower the timing.
  bool b = true;
  // loop from the lowest pin to the highest:
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    // turn the pin on:
    if (digitalRead(13)==1){
      delay(700);
      if (digitalRead(13)==0){
        b= !b;
      }
    }
    if(b){
      digitalWrite(thisPin, HIGH);
      delay(timer);
      // turn the pin off:
      digitalWrite(thisPin, LOW); 
    }
    if(!b){
      digitalWrite(thisPin, HIGH);
      timer-=10;
    }
    if(timer==0){
      print("YOU LOSE");
    }

  }

  // loop from the highest pin to the lowest:
  for (int thisPin = 7; thisPin >= 2; thisPin--) { 
     // turn the pin on:
    if (digitalRead(13)==1){
      delay(700);
      if (digitalRead(13)==0){
        b= !b;
      }
    }
    if(b){
      digitalWrite(thisPin, HIGH);
      delay(timer);
      // turn the pin off:
      digitalWrite(thisPin, LOW); 
    }
    if(!b){
      digitalWrite(thisPin, HIGH);
      timer-=10;
    }
    if(timer==0){
      print("YOU LOSE");
    }

}
