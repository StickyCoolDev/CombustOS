// include the library code:
#include <LiquidCrystal.h> // initialize the library with the numbers of the interface pins – The numbers
//are the pin connected in sequence from RS to DB7


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define SelectedIcon 7
#define NotSelectedIcon 6
#define MoveButton 8

int SelectedPage = 1;

byte Selected[] = { B00000, B00000, B00100, B01110, B11111, B01110, B00100, B00000 };
byte NotSelected[] = { B00000, B00000, B00000, B00100, B01110, B00100, B00000, B00000 };


void setup(){
  lcd.begin(16, 2);
  lcd.createChar(SelectedIcon, Selected);
  lcd.setCursor(1, 0);
  
  
  lcd.createChar(NotSelectedIcon, NotSelected);
  
  pinMode(MoveButton, INPUT);
  //attachInterrupt((MoveButton), NextPage, FALLING);
  NextPage();
}

void NextPage(){
  lcd.clear();
  if (SelectedPage >= 9)
  {
    SelectedPage = 1;
  }else
  {
    SelectedPage++;
  }
  for (int i = 1; i <= 9; i++){
    lcd.setCursor(i+3, 1);
    if (i == SelectedPage)
    {
      lcd.write(SelectedIcon);
      lcd.print(" ");
      continue;
    }
    lcd.write(NotSelectedIcon);
    lcd.print(" ");
    
  }
  if (SelectedPage == 1){
    lcd.setCursor(1, 0);
    lcd.print("reset");
  }
  if (SelectedPage == 2){
    lcd.setCursor(1, 0);
    lcd.print("cool");
  }
  if (SelectedPage == 3){
    lcd.setCursor(1, 0);
    lcd.print("LCD screen");
  }
}

void loop() {
  
  if (digitalRead(MoveButton) == HIGH){
    NextPage();
    delay(200);
  }
  
  //Set page
}