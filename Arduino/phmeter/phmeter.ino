#include <Arduino.h>

int pHSense = A0;
int samples = 10;
float adc_resolution = 1024.0;

void setup()
{
    Serial.begin(9600);
    delay(100);
    Serial.println("cimpleo pH Sense");
}

float ph (float voltage) {
    return 7 + ((2.5 - voltage) / 0.18);
    //return 14*voltage/5;
    //return ((-5.7)*voltage)+21.34;
}

void loop()
{
    int measurings=0;

    for (int i = 0; i < samples; i++)
    {
        measurings += analogRead(pHSense);
        delay(10);

    }

    float voltage = (5 / adc_resolution * measurings/samples)-0.07;
    Serial.print("pH= ");
    Serial.println(ph(voltage));
    Serial.println(voltage);
    delay(3000);
}
