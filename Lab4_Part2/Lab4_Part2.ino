void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT, A0);
  pinMode(OUTPUT, 10);
  pinMode(OUTPUT, 9);
  Serial.begin(9600);
}

void loop() {
  float A0state= float(analogRead(A0)) *5.0/1023.0;
  Serial.println(A0state);
  if (A0state > 4.55){
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    delay(100);
  }else{
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(100);
  }
  // put your main code here, to run repeatedly:
  
}
