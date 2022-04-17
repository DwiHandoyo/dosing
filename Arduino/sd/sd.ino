#include <SPI.h>
#include <SD.h>

File myFile;

// change this to match your SD shield or module;
const int chipSelect = 10;
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

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  
}
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

void loop()
{
  delay(1000);
  plant pointer = getPlantData(2);
  Serial.println(pointer.temperatureLow);
  // nothing happens after setup
}
