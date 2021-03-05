const int kPinPot1 = A0;
const int kPinPot2 = A1;
const int kPinPot3 = A2;
const int kPinLed_R = 6;
const int kPinLed_G = 10;
const int kPinLed_B = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(kPinLed_R, OUTPUT);
  pinMode(kPinLed_G, OUTPUT);
  pinMode(kPinLed_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue;
  int ledValue;
  potValue = analogRead(kPinPot1);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(kPinLed_R, ledValue);

  potValue = analogRead(kPinPot2);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(kPinLed_G, ledValue);

  potValue = analogRead(kPinPot3);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(kPinLed_B, ledValue);

  
}
