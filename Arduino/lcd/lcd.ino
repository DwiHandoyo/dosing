#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
const int backButton = 4;
const int nextButton = 3;
const int selectButton = 2;
const int gndPin = 11;
const int millisInDay = 86400000;


bool backIsPressed;
bool nextIsPressed;
bool selectIsPressed;
int count;
unsigned long startTine;
unsigned long tempTime;
int days;
int i;

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

class Screen{
 public:
 
   uint8_t layer;
   void showScreen(){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(appreance[layer][0]);
     lcd.setCursor(0,1);
     lcd.print(appreance[layer][1]);
   };

   void refreshScreen(){
     refreshAppreance();
     showScreen();
   };

   void select(){
     if(layer<1){
       this->layer++;
     }
   }

   void back(){
     if(layer>0){
       this->day = 0;
       this->layer--;
     }
   }

   void addDay(){
     this->day++;
   }

   void setPlant(String plant){
     this->plant= plant;
   }

 private:
   int position;
   int day;
   int plantIndex;
   String plant;
   void refreshAppreance(){
     appreance[0][0] = "Pilih Tanaman";
     appreance[0][1] = plant;
     appreance[1][0] = plant;
     appreance[1][1] = "days: " + String(this->day);
   };
   String appreance[2][2];
};

Screen screen;
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
  delay(1000);
   screen.setPlant(plants[i%3].plantName);
   screen.refreshScreen();
  if(backIsPressed){
    screen.back();
    screen.refreshScreen();
    backIsPressed = false;
  }
  if(selectIsPressed){
    Serial.println(digitalRead(selectButton));
    screen.select();
    screen.refreshScreen();
    selectIsPressed = false;
  }
  if(nextIsPressed & screen.layer == 0){
    screen.setPlant(plants[i%3].plantName);
    screen.refreshScreen();
    nextIsPressed = false;
  }
  if(millis()-tempTime > millisInDay | tempTime -millis() < sizeof(unsigned long) - millisInDay){
    tempTime = millis();
    screen.addDay();
    screen.refreshScreen();
  }
}

void back(){
  backIsPressed = true;
}

void next(){
  i++;
  nextIsPressed = true;
}

void select(){
  selectIsPressed = true;
}
