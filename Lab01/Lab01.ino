/*Anwitha and Tarushii 
 * 10/18/18
 * Project #1    Aciivity # 1
 * Title: Changing the flashing time of an LED
 * In this program, we declared a variable var, which incresed ten fold each time the program ran through the loop. 
 * We had an LED connected to the board. Each time the program was run, the LED lit up, waited for var/2 milliseconds, turned off, then waited again for var/2 milliseconds before lighting up again.
 * We also printed the variable var to the serial monitor to keep track of how the variable grew exponentially.
 */
double var = 8*11;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  var = var*10;
  //Serial.println("Hello, this is a message from the great beyond!"); //displays "Hello, this is a message from the great beyond!" and the cursor goes to the next line
  //Serial.println("What's 7 x 11?"); // displays "What's 7 x 11?" and the cursor goes to the next line
  //Serial.print("The answer is: "); //displays "The answer is: " and the cursor goes to the next line
  Serial.println(var); //displays the current value of the variable var
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(var/2);                       // waits for var/2 milliseconds
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(var/2);                     //waits for var/2 milliseconds
  //delay(1000); // freezes for one second, does not look at the next line of code
  //Serial.println(7*11, HEX); ////displays 77

}
