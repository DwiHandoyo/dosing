#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
const int backButton = 2;
const int nextButton = 3;
const int selectButton = 8;
const int gndPin = 11;
const int millisInDay = 86400000;


bool backIsPressed;
bool nextIsPressed;
bool selectIsPressed;
int count;
unsigned long startTine;
unsigned long tempTime;
int days;

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
  pinMode(selectButton, INPUT);
  attachInterrupt(digitalPinToInterrupt(backButton), back, HIGH);
  attachInterrupt(digitalPinToInterrupt(nextButton), next, HIGH);
  attachInterrupt(digitalPinToInterrupt(selectButton), select, HIGH);
  lcd.print("Mesin Dosing");
  delay(1000);
}

void loop(){
  tempTime = millis();
  Serial.print(digitalRead(nextButton));
  if(backIsPressed){
    lcd.clear();
    lcd.print("back");
    backIsPressed = false;
  }
  if(nextIsPressed){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pilih Tanaman");
    lcd.setCursor(0,1);
    lcd.print(plants[i%3].plantName);
    nextIsPressed = false;
  }
  if(selectIsPressed){

    Serial.println(digitalRead(selectButton));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(plants[i%3].plantName);
    lcd.setCursor(0,1);
    lcd.print(days);
    selectIsPressed = false;
  }
  delay(1000);
  if(millis()-tempTime > millisInDay | tempTime -millis() < sizeof(unsigned long) - millisInDay){
    tempTime = millis();
    days ++;
  }
}

void back(){
  backIsPressed = true;
}

void next(){
  nextIsPressed = true;
  i++;
}

void select(){
  Serial.println("selsect");
  selectIsPressed = true;

}
