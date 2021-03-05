void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);

}
void loop() {
  float A0state= float(analogRead(A0)) *5.0/1023.0;
  Serial.println(A0state);
  delay(500);

// put your main code here, to run repeatedly:

}
