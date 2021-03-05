#include <avr/eeprom.h>

void setup() {
  Serial.begin(9600);
  uint16_t seed = eeprom_read_word(1);
  randomSeed(seed++);
  eeprom_write_word(1, seed);
}

void loop() {
  Serial.println(random(0, 100));
  delay(500);
}
