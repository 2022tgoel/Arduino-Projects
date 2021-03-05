void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 10; i++) {//change to 10
    pinMode(i, OUTPUT);
  }
  pinMode(13, INPUT);

}
int lednum = 2;//goes to 10
int d = 0;
int del = 100;
int pushbut = 1;//use resistor before (pressed means 0's)
int r = 1;
void loop() {

  pushbut = digitalRead(13);
  if (pushbut &&r){ //not pressed
    
    if (d){
      digitalWrite(lednum, LOW);
      digitalWrite(lednum-1, HIGH);
      delay(del);
      lednum--;
    }else{
      digitalWrite(lednum, LOW);
      digitalWrite(lednum+1, HIGH);
      delay(del);
      lednum++;
    }
    if (lednum==10 || lednum==2){//change to 11
      d = !(d);
    }
  }
  if (!pushbut && r){
    while (!(digitalRead(13))){
      delay(1);
    }
    while(digitalRead(13)){
      delay(1);
    }
    while(!(digitalRead(13))){
      pushbut=1;
    }
    if (lednum==6){
      Serial.println("YOU WIN");
    }
    del-=10;
    if (del<10){
      Serial.println("YOU LOSE");
      r = 0;
    }
    
  }

}
