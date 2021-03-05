void setup() {
  Serial.begin(9600); //Serial Monitor setup
  randomSeed(analogRead(0)); //---------------------------------------------------------------------------------------------understand??
  //LED Setup - pins 12 and 13
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Pushbutton Setup - pins 3 and 4
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  //NOTE: These are Pull-down pushbuttons, Pull-up pushbuttons can be used with slight modifications
}

//declare scores for both player outside of loop
int score1 = 0; //Change to 1 if pull-up
int score2 = 0; //Change to 1 if pull-up
//state represents the state of pushbutton for both players
//At the beginning both pushbuttons are not pressed, so state is 0
int state1 = 0;
int state2 = 0;
//For code that only runs the first time:
bool firstRun = true; //bool that toggles when first run has been completed
String name1 = "";
String name2 = "";
//Pins 3 & 12 MUST be associated with player 1 otherwise code will not work (vice versa for player 2)
//Make sure player1 presses the pushbutton connected to pin 3 (vice versa for player 2)
void loop() {
  if (firstRun){ //only runs once    
    Serial.println("Player 1! Please enter you name.");  
    while (Serial.available()==0) { //Serial.available() checks number or bytes available to read                                        
      delay(1); //waits for player one to enter name
    }
    name1=Serial.readString();  //Reading the Input string from Serial port and assigning to name1
    Serial.println("Player 2! Please enter you name.");  
    while (Serial.available()==0) { //Serial.available() checks number or bytes available to read                                       
      delay(1); //waits for player two to enter name
    }  
    name2=Serial.readString();  //Reading the Input string from Serial port and assigning to name2
    Serial.println("SO ARE YOU READY?");
    delay(random(2000, 3000));
    Serial.println("GET SET!");
    delay(random(3000, 4000));
    //random creates a level of unpredictability of when the game will start
    Serial.println("GOOOOOO!"); 
    firstRun = false; //toggles bool so this code doesn't run again
  
  }
  //checks if state of pushbutton (pressed or not pressed) has changed
  if (digitalRead(3)!=state1){
    score1++; //if state has changed adds 1 to score
    state1 = digitalRead(3); //updates state
  }
  //NOTE: score double counts the number of presses 
  //It would increment when state goes from 0 to 1 AND when it goes from 1 to 0
  //repeated code for second player's pushbutton
  if (digitalRead(4)!=state2){
    score2++;
    state2 = digitalRead(4);
  }
  ///* This code can show you how the score progresses if you wish to uncomment it:
  Serial.print(score1);
  Serial.print(" ");
  Serial.println(score2);
  //*/
  //If loop for when player 1 wins:
  if (score1 == 40){ //NOTE: This code runs when the number of clicks reaches 20, not 40
    digitalWrite(12, HIGH); //LED lights up to indicate winner
    //Announces winner
    Serial.print("Congratulations "+name1); //Prints name of winner
    Serial.println("You won!");
    while(1); //forever loop
  }
  //Same if loop for player2, if they win
  if (score2 == 40){ //------------------------------------------------------------------------------------------------------------change?
    digitalWrite(13, HIGH); //LED lights up to indicate winner
    //Announces winner
    Serial.print("Congratulations "+name2);
    Serial.println("You won!");
    while(1); //forever loop
  }
  //This runs at O(1) after first run through loop
}
