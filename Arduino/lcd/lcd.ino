#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
const int backButton = 2;
const int nextButton = 3;
const int gndPin = 11;

bool backIsPressed;
int count;
String input = "";

LiquidCrystal_I2C lcd(0x27, 16, 2);

struct plant{
    String plantName;
    float phHigh;
};

plant jandaBolong = {"Janda Bolong", 10};
plant kantongSemar = {"Kantong Semar", 9.5};
plant cocorBebek = {"Cocor Bebek", 9.75};
plant plants [3] = {jandaBolong, kantongSemar, cocorBebek};

int i;
boolean yakinSegini = false;
void setup(){
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

  pinMode(backButton, INPUT);
  pinMode(nextButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(backButton), back, HIGH);
  attachInterrupt(digitalPinToInterrupt(nextButton), next, HIGH);
  lcd.print("Mesin Dosing");
  delay(1000);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pilih Tanaman");
  lcd.setCursor(0,1);
  lcd.print(plants[i%3].plantName);
  Serial.print(digitalRead(nextButton));
  if(backIsPressed){
    lcd.clear();
    lcd.print("back");
    backIsPressed = false;
  }
  delay(1000);
}

void back(){
  backIsPressed = true;
}

void next(){
  i++;
}
