#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>

File myFile;
const int backButton = 4;
const int nextButton = 3;
const int selectButton = 2;
const int gndPin = 11;
const int millisInDay = 86400000;
const uint8_t plantNumber = 2;
const int chipSelect = 10;

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
  float phLow;
  float phHigh;
  short int ppmLow;
  short int ppmHigh;
  short int temperatureLow;
  short int temperatureHigh;
  short int durationLow;
  short int durationHigh;
};

//plant artichoke = {"Artichoke", 6.5 ,  7.5, 560 ,  1260, 0, 30, 60};
//plant asparagus = {"Asparagus", 6 ,  6.8, 980 ,  1200, 15, 25, 240, 330};
//plant bawangDaun = {"Bawang daun", 6.5 ,  7, 980 ,  1260, 18, 25, 55, 75};
//plant bayam = {"Bayam", 6 ,  7, 1260 ,  1610, 25, 30, 25, 30};
//plant brokoli = {"Brokoli", 6 ,  6.8, 1960 ,  2450, 21, 32, 60, 95};
//plant brussell = {"Brussell kecambah", 6.5, 1750 ,  2100, 0, 70, 95};
//plant endive = {"Endive", 5.5, 1400 ,  1680, 15, 18, 50, 85};
//plant kailan = {"Kailan", 5.5 ,  6.5, 1050 ,  1400, 22, 35, 40, 56};
//plant kangkung = {"Kangkung", 5.5 ,  6.5, 1050 ,  1400, 25, 30, 20, 30};
//plant kubis = {"Kubis", 6.5 ,  7, 1750 ,  2100, 19, 21, 80, 115};
//plant kubisBunga = {"Kubis bunga", 6.5 ,  7, 1750 ,  2100, 25, 30, 47, 63};
//plant pakcoy = {"Pakcoy", 7, 1050 ,  1400, 23, 30, 30, 45};
//plant caisim = {"Caisim", 5.5 ,  6.5, 1050 ,  1400, 25, 30, 21, 38};
//plant sawiPahit = {"Sawi pahit", 6 ,  6.5, 840 ,  1680, 19, 21, 65, 70};
//plant sawi = {"Sawi pagoda (tatsoi)", 5.5 ,  6.5, 1050 ,  1400, 18, 25, 25, 45};
//plant seledri = {"Seledri", 6.5, 1260 ,  1680, 15, 24, 24, 100};
//plant selada = {"Selada", 6 ,  7, 560 ,  840, 23, 25, 45, 85};
//plant silverbeet = {"Silverbeet", 6 ,  7, 1260 ,  1610, 16, 18, 45, 65};
//
//plant buncis = {"Buncis", 6, 1400 ,  2800, 20, 25, 45, 50};
//plant cabai = {"Cabai", 6 ,  6.5, 1260 ,  1540, 18, 30, 60, 90};
//plant kacangPolong = {"Kacang polong", 6 ,  7, 980 ,  1260, 28, 32, 80, 100};
//plant kembangKol = {"Kembang kol", 6 ,  7, 1050 ,  1400, 28, 32, 45, 75};
//plant okra = {"Okra", 6.5, 1400 ,  1680, 28, 32, 65, 95};
//plant paprika = {"Paprika", 6 ,  6.5, 1260 ,  1540, 21, 27, 75, 95};
//plant tomat = {"Tomat", 6 ,  6.5, 1400 ,  3500, 24, 32, 60, 90};
//plant terong = {"Terong", 6, 1750 ,  2450, 22, 30, 65, 85};
//plant timun = {"Timun", 5.5, 1190 ,  1750, 20, 32, 32, 47};
//plant timunJepang = {"Timun jepang", 6, 1260 ,  1680, 18, 30, 75, 115};
//
//plant blueberry = {"Blueberry", 4 ,  5, 1260 ,  1400, 23, 33, 3, 60};
//plant kismisHitam = {"Kismis hitam", 6, 980 ,  1260, 24, 27, 45, 255};
//plant kismisMerah = {"Kismis merah", 6, 1400 ,  1680, 23, 34, 45, 275};
//plant labu = {"Labu", 5.5 ,  7.5, 1260 ,  1680, 18, 27, 60, 90};
//plant melon = {"Melon", 5.5 ,  6, 1400 ,  1750, 25, 30, 65, 75};
//plant markisa = {"Markisa", 6.5, 840 ,  1680, 20, 30, 9, 15};
//plant nanas = {"Nanas", 5.5 ,  6, 1400 ,  1680, 21, 28, 1, 24};
//plant pisang = {"Pisang", 5.5 ,  6, 1260 ,  1540, 15, 35, 1, 24};
//plant pepaya = {"Pepaya", 6.5, 840 ,  1680, 25, 30, 6, 12};
//plant strawberry = {"Strawberry", 6, 1260 ,  1540, 17, 20, 90, 240};
//plant semangka = {"Semangka", 5.8, 1260 ,  1680, 20, 30, 58, 75};
//
//plant africanViolet = {"African violet", 6 ,  7, 840 ,  1050, 16, 32, 45, 495};
//plant anthurium = {"Anthurium", 5 ,  6, 1120 ,  1400, 23, 40, 45, 515};
//plant aphelandra = {"Aphelandra", 5 ,  6, 1260 ,  1680, 16, 33, 45, 535};
//plant aster = {"Aster", 6 ,  6.5, 1260 ,  1680, 23, 41, 45, 555};
//plant begonia = {"Begonia", 6.5, 980 ,  1260, 16, 34, 45, 575};
//plant bromeliads = {"Bromeliads", 5 ,  7.5, 560 ,  840, 23, 42, 45, 595};
//plant caladium = {"Caladium", 6 ,  7.5, 1120 ,  1400, 16, 35, 45, 615};
//plant canna = {"Canna", 6, 1260 ,  1680, 23, 43, 45, 635};
//plant carnation = {"Carnation", 6, 1260 ,  1680, 16, 36, 45, 655};
//plant krisan = {"Chrysanthemum (Krisan)", 6 ,  6.2, 1400 ,  1750, 23, 44, 45, 675};
//plant cymbidiums = {"Cymbidiums", 5.5, 420 ,  560, 16, 37, 45, 695};
//plant dahlia = {"Dahlia", 6 ,  7, 1050 ,  1400, 23, 45, 45, 715};
//plant dieffenbachia = {"Dieffenbachia", 5, 1400 ,  1680, 16, 38, 45, 735};
//plant cracaena = {"Cracaena", 5 ,  6, 1400 ,  1680, 23, 46, 45, 755};
//plant ferns = {"Ferns", 6, 1120 ,  1400, 16, 39, 45, 775};
//plant ficus = {"Ficus", 5.5 ,  6, 1120 ,  1400, 23, 47, 45, 795};
//plant freesia = {"Freesia", 6.5, 700 ,  1400, 16, 40, 45, 815};
//plant impatiens = {"Impatiens", 5.5 ,  6.5, 1260 ,  1400, 23, 48, 45, 835};
//plant gerbera = {"Gerbera", 5 ,  6.5, 1400 ,  1750, 16, 41, 45, 855};
//plant gladiolus = {"Gladiolus", 5.5 ,  6.5, 1400 ,  1680, 23, 49, 45, 875};
//plant monstera = {"Monstera", 5 ,  6, 1400 ,  1680, 16, 42, 45, 895};
//plant palms = {"Palms", 6 ,  7.5, 1120 ,  1400, 23, 50, 45, 915};
//plant mawar = {"Roses (mawar)", 5.5 ,  6, 1050 ,  1750, 16, 43, 45, 935};
//plant stock = {"Stock", 6 ,  7, 1120 ,  1400, 23, 51, 45, 955};
//
//plant kemangi = {"Basil (kemangi)", 5.5 ,  6.5, 700 ,  1120, 7, 27, 42, 48};
//plant chicory = {"Chicory", 5.5 ,  6, 1400 ,  1600, 15, 18, 50, 85};
//plant chives = {"Chives", 6 ,  6.5, 1260 ,  1540, 16, 27, 45, 65};
//plant fennel = {"Fennel", 6.4 ,  6.8, 700 ,  980, 22, 25, 210, 260};
//plant lavender = {"Lavender", 6.4 ,  6.8, 700 ,  980, 16, 27, 12, 16};
//plant lemonBalm = {"Lemon balm", 5.5 ,  6.5, 700 ,  1120, 22, 28, 120, 150};
//plant marjoram = {"Marjoram", 6, 1120 ,  1400, 15, 20, 67, 105};
//plant mint = {"Mint", 5.5 ,  6, 1400 ,  1680, 22, 30, 120, 150};
//plant mustardCress = {"Mustard cress", 6 ,  6.5, 840 ,  1680, 23, 28, 35, 75};
//plant parsley = {"Parsley", 5.5 ,  6, 560 ,  1260, 23, 28, 70, 95};
//plant rosemary = {"Rosemary", 5.5 ,  6, 700 ,  1120, 10, 27, 65, 115};
//plant sage = {"Sage", 5.5 ,  6.5, 700 ,  1120, 15, 21, 75, 95};
//plant thyme = {"Thyme", 5.5 ,  7, 560 ,  1120, 16, 27, 70, 85};
//plant watercress = {"Watercress", 6.5 ,  6.8, 280 ,  1260, 8, 15, 90, 120};
//
//plant bawangMerah = {"Bawang merah", 6 ,  6.7, 980 ,  1260, 25, 32, 55, 90};
//plant bawangPutih = {"Bawang putih", 6, 980 ,  1260, 15, 25, 90, 120};
//plant kentang = {"Kentang", 5 ,  6, 1400 ,  1750, 17, 21, 80, 120};
//plant lobak = {"Lobak", 6 ,  6.5, 1260 ,  1680, 15, 21, 23, 70};
//plant talas = {"Talas", 5 ,  5.5, 1750 ,  2100, 25, 30, 7, 10};
//plant ubi = {"Ubi", 6, 980 ,  1260, 25, 28, 3, 6};
//plant ubiJalar = {"Ubi jalar", 5.5 ,  6, 1400 ,  1750, 25, 30, 3, 6};
//plant wortel = {"Wortel", 6.3, 1120 ,  1400, 15, 21, 60, 85};
//
//
//plant plants [85] = {
//                      artichoke, 
//                      asparagus, 
//                      bawangDaun, 
//                      bayam, 
//                      brokoli, 
//                      brussell, 
//                      endive, 
//                      kailan, 
//                      kangkung, 
//                      kubis, 
//                      kubisBunga, 
//                      pakcoy, 
//                      caisim, 
//                      sawiPahit, 
//                      sawi, 
//                      seledri, 
//                      selada, 
//                      silverbeet, 
//                      buncis, 
//                      cabai, 
//                      kacangPolong, 
//                      kembangKol, 
//                      okra, 
//                      paprika, 
//                      tomat, 
//                      terong, 
//                      timun, 
//                      timunJepang, 
//                      blueberry, 
//                      kismisHitam, 
//                      kismisMerah, 
//                      labu, 
//                      melon, 
//                      markisa, 
//                      nanas, 
//                      pisang, 
//                      pepaya, 
//                      strawberry, 
//                      semangka, 
//                      africanViolet, 
//                      anthurium, 
//                      aphelandra, 
//                      aster, 
//                      begonia, 
//                      bromeliads, 
//                      caladium, 
//                      canna, 
//                      carnation, 
//                      krisan, 
//                      cymbidiums, 
//                      dahlia, 
//                      dieffenbachia, 
//                      cracaena, 
//                      ferns, 
//                      ficus, 
//                      freesia, 
//                      impatiens, 
//                      gerbera, 
//                      gladiolus, 
//                      monstera, 
//                      palms, 
//                      mawar, 
//                      stock, 
//                      kemangi, 
//                      chicory, 
//                      chives, 
//                      fennel, 
//                      lavender, 
//                      lemonBalm, 
//                      marjoram, 
//                      mint, 
//                      mustardCress, 
//                      parsley, 
//                      rosemary, 
//                      sage, 
//                      thyme, 
//                      watercress, 
//                      bawangMerah, 
//                      bawangPutih, 
//                      kentang, 
//                      lobak, 
//                      talas, 
//                      ubi, 
//                      ubiJalar, 
//                      wortel
//};

String readFile(String fileName){
  myFile = SD.open(fileName);
  String param = "";
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      char temp = (char)myFile.read();
      Serial.print(temp);
      param += temp;
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println(fileName);
  }
  return param;
}

plant getPlantData(int index){
  
  String plantName = readFile(String(index) + "/name.txt");
  String phLow = readFile(String(index) + "/ph-low.txt");
  String phHigh = readFile(String(index) + "/ph-high.txt");
  String ppmLow = readFile(String(index) + "/ppm-low.txt");
  String ppmHigh = readFile(String(index) + "/ppm-high.txt");
  String temperatureLow = readFile(String(index) + "/tmp-low.txt");
  String temperatureHigh = readFile(String(index) + "/tmp-high.txt");
  String durationLow = readFile(String(index) + "/dur-low.txt");
  String durationHigh = readFile(String(index) + "/dur-high.txt");
  
  return {plantName, phLow.toFloat() ,  phHigh.toFloat() ,  ppmLow.toFloat() ,  ppmHigh.toFloat(), temperatureLow.toInt(),  temperatureLow.toInt(), durationLow.toInt(), durationHigh.toInt()};
}
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

  
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
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
  plant pointer = getPlantData(i%plantNumber);
  screen.setPlant(pointer.plantName);
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
    screen.setPlant(pointer.plantName);
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
