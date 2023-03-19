#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

#include <SoftwareSerial.h>
SoftwareSerial espSerial(2,3);
#define DEBUG true

String mySSID ="OnePlus 7 Pro";
String myPWD="12345678";
String myHOST="184.106.153.149";
String myPORT="80";
double a=0,b=0,c=0;

void setup(void) {
  Serial.begin(9600);  
  espSerial.begin(9600);
  if(!accel.begin()){
      Serial.println("No ADXL345 sensor detected.");
      while(1);
   }
  
  espData("AT+RST", 1000, DEBUG);                      //Reset the ESP8266 module
  espData("AT+CWMODE=1", 1000, DEBUG);                 //Set the ESP mode as station mode
  espData("AT+CWJAP=\""+ mySSID +"\",\""+ myPWD +"\"", 1000, DEBUG);
  
  Serial.println("Connected");
}

void loop(void){
   sensors_event_t event; 
   accel.getEvent(&event);
   a=event.acceleration.x;
   b=event.acceleration.y;
   c=event.acceleration.z;
   
   Serial.print("X: "); Serial.print(a); Serial.print("  ");
   Serial.print("Y: "); Serial.print(b); Serial.print("  ");
   Serial.print("Z: "); Serial.print(c); Serial.print("  ");
   Serial.println("m/s^2 ");
   
    String sendData = "GET /update?api_key=XWL55RDLFTZ5V7CT&field2="+String(a)+"&field3="+String(b)+"&field4="+String(c);
    espData("AT+CIPMUX=1", 500, DEBUG);       //Allow multiple connections
    espData("AT+CIPSTART=0,\"TCP\",\""+ myHOST +"\","+ myPORT, 500, DEBUG);
    espData("AT+CIPSEND=0," +String(sendData.length()+4),500,DEBUG);  
    espSerial.find(">"); 
    espSerial.println(sendData);
   
}

String espData(String command, const int timeout, boolean debug)
{
  Serial.print("AT Command ==> ");
  Serial.print(command);
  Serial.println("     ");
  
  String response = "";
  espSerial.println(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (espSerial.available())
    {
      char cc = espSerial.read();
      response += cc;
    }
  }
  if (debug)
  {
    Serial.println(response);
  }
  return response;
}
