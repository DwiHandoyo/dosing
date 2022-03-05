#define analogInPin  A1  

int sensorValue; 
float outputValueConductivity; 
float outputValueTDS; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);

  //outputValueConductivity = (0.2142*sensorValue)+494.93;
  outputValueConductivity = (26.68*sensorValue) - 9645.3;
  //outputValueConductivity = (2.8477*sensorValue) - 1007.9;
  
  //outputValueTDS = (0.3417*sensorValue)+281.08;
  outputValueTDS = (12.509*sensorValue) - 4486.7;
  //outputValueTDS = (5.6447*sensorValue) - 1989.2;
  
  //print the results to the serial monitor:
  Serial.print("sensor ADC = ");
  Serial.print(sensorValue);
  Serial.print("  conductivity (uSiemens)= ");
  Serial.print(outputValueConductivity);
  Serial.print("  TDS(ppm)= ");
  Serial.println(outputValueTDS);

  delay(500);
}
