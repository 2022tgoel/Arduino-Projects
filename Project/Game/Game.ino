#include <avr/eeprom.h> //imports EEPROM library, EEPROM is used to store randomSeed() values so they can be changed between runs
//analogRead() would be the alternative, but it is not as random since electrical singals surrounding an unused pin are generally pretty similar 

void setup() {
  Serial.begin(9600); //Serial Monitor setup
  uint16_t seed = eeprom_read_word(1); //Reads the value stored in EEPROM (Electronically erasable programmable ROM) address 1 (this is where seed is stored) 
  randomSeed(seed++); //sets that value as seed for random() and adds one to seed so the seed the next time this porgram is run is guaranteed to be different
  eeprom_write_word(1, seed); //stores seed in EEPROM so it'll be there for the next time this code is run
  //LED Setup - pins 12 and 13
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Pushbutton Setup - pins 3 and 4
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  //NOTE: These are Pull-down pushbuttons, Pull-up pushbuttons can be used with slight modifications
}

//declare scores for both player outside of loop
int score1 = 0; 
int score2 = 0; 
//state represents the state of pushbutton for both players
//At the beginning both pushbuttons are not pressed, so state is 0
int state1 = 0; //Change to 1 if pull-up
int state2 = 0;
//For code that only runs the first time:
bool firstRun = true; //bool that toggles when first run has been completed
//names of players
String name1 = "";
String name2 = "";
//Pins 3 & 12 MUST be associated with player 1 otherwise code will not work (vice versa for player 2)
//Make sure player1 presses the pushbutton connected to pin 3 (vice versa for player 2)
void loop() {
  if (firstRun){ //only runs once 
    //Takes in names:   
    Serial.println("Player 1! Please enter you name.");  
    while (Serial.available()==0) { //Serial.available() checks number or bytes available to read                                        
      delay(1); //waits for player one to enter name
    }
    //Now bytes are available so...
    name1=Serial.readString();  //Reading the Input string from Serial port and assigning to name1
    Serial.println("Player 2! Please enter you name.");  
    //Process repeated for second player
    while (Serial.available()==0) {                                       
      delay(1); //waits for player two to enter name
    }  
    name2=Serial.readString();  //Reading the Input string from Serial port and assigning to name2
    //Messages given to player before game has begun
    Serial.println("SO ARE YOU READY?");
    delay(random(2000, 3000));//level of unpredictability of when the game will start 
    Serial.println("GET SET!");
    delay(random(3000, 4000));
    //random creates a level of unpredictability of when the game will start
    Serial.println("GOOOOOO!"); 
    firstRun = false; //toggles bool so this code doesn't run again
  }
  //Now for the game code
  //checks if state of pushbutton (pressed or not pressed) has changed
  if (digitalRead(3)!=state1){
    score1++; //if state has changed adds 1 to score
    state1 = digitalRead(3); //updates state
  }
  //NOTE: score double counts the number of presses since the state changes twice in one press
  //It would increment when state goes from 0 to 1 AND when it goes from 1 to 0
  //repeated code for second player's pushbutton
  if (digitalRead(4)!=state2){
    score2++;
    state2 = digitalRead(4);
  }
  //This code can show you how the score progresses if you wish to uncomment it:
  
  Serial.print(score2/2); //switched b/c we read left to right but players go from right to left
  Serial.print(" ");
  Serial.println(score1/2);
  
  
  //If loop for when player 1 wins:
  if (score1 == 200){ //NOTE: This code runs when the number of clicks reaches 100, due to dounble counting
    digitalWrite(12, HIGH); //LED lights up to indicate winner
    //Announces winner

    Serial.print("Congratulations "+name1); //Prints name of winner
    Serial.println(" you won!");
    while(1); //forever loop essentially ends the program since the game has finished
  }
  //Same if loop for player 2, if they win
  if (score2 == 200){ 
    digitalWrite(13, HIGH); //LED lights up to indicate winner
    //Announces winner
    Serial.print("Congratulations "+name2);
    Serial.println(" you won!");
    while(1); //forever loop
  }
  //This program runs at O(1) after first run through loop
}
