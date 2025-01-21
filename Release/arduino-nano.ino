// CombustOS 1.0 beta

//library's 
#include <LiquidCrystal.h> // initialize the library with the numbers of the interface pins – The numbers are the pin connected in sequence from RS to DB7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// Set it according to your screen placement



// defines 

//buttons
#define buttonA 9
#define ButtonB 10

// add many buttons as you want defining them , add them to the array
#define buttonArray [ButtonA, ButtonB]


void setPORTB(byte value){
  PORTB = value;
}

void setup(){
  for (buttons in buttonArray){
    pinMode(buttons, INPUT_PULLDOWN)
  };
  
  lcd.begin(16, 2); // Set your correct display height and width
}

void loop() {
  
}