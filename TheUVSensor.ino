#define LED_PIN 11
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Serial.print(readSensor());
}

void loop() {
  Serial.print(readSensor());
  Serial.print("\n");
  // put your main code here, to run repeatedly:

}

float readSensor()
{
  String UVIndex = "0";
  int sensorValue = 0;
  float UVInt = 0; 
  
  sensorValue = analogRead(A0);                        //connect UV sensor to Analog 0   
  int voltage = (sensorValue * (5.0 / 1023.0))*1000;  //Voltage in miliVolts
  
  if(voltage<50)
  {
    UVInt = 0;
  }else if (voltage>50)
  {
    UVInt = ((0.0106 * voltage) - 1.37); 
  }
  return UVInt;
}