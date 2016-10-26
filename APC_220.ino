// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int led = 9;

void setup()   
{ 
  pinMode(led, OUTPUT);
  Serial.begin(19200);    //  Definition UART port rate 19200, according to serial port of APC220
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop()
{     
                                                
// when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    

    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
