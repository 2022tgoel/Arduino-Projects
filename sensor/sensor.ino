#define BEAM 5
void setup()
{
  pinMode(BEAM,INPUT);
  Serial.begin(9600); 
}
void loop()
{
  Serial.println(digitalRead(BEAM));
  delay(250);  
}
