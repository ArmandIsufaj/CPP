// EE3600 / 3700 Design-III
#include <DS3231.h> 
#include <SPI.h> 
#include <SD.h> 
#include <dht.h> 
#define DHT11_PIN 7 
dht DHT; 
const int chipSelect = 4; 

DS3231  rtc(A4, A5);
void setup()
{
  
  Serial.begin(9600);
  Initialize_SDcard();
  Initialize_RTC();
  Initialize_PlxDaq();
}
void loop()
{
  Read_DateTime();
  Read_DHT11();
  Write_SDcard();
  Write_PlxDaq();
  delay(5000);  
}
void Write_PlxDaq()
  {
    Serial.print("DATA"); 
    Serial.print(","); 
    Serial.print(rtc.getDateStr()); 
    Serial.print(","); 
    Serial.print("TIME"); 
    Serial.print(","); 
    Serial.print(DHT.temperature); 
    Serial.print(","); 
    Serial.print(DHT.humidity); 
    Serial.print(","); 
    Serial.println(); 
  }
void Initialize_PlxDaq()
{
Serial.println("CLEARDATA");
Serial.println("LABEL,Date,Time,Temperature,Humidity");
}
void Write_SDcard()
{
    
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  
  if (dataFile) {
    dataFile.print(rtc.getDateStr()); 
    dataFile.print(","); 
    dataFile.print(rtc.getTimeStr()); 
    dataFile.print(","); 
    dataFile.print(DHT.temperature);
    dataFile.print(","); 
    dataFile.print(DHT.humidity); 
    dataFile.print(","); 
    dataFile.println(); 
    dataFile.close(); 
  }
  else
  Serial.println("OOPS!! SD card writing failed");
}
void Initialize_SDcard()
{
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    
    return;
  }
   
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  
  if (dataFile) {
    dataFile.println("Date,Time,Temperature,Humidity"); //Write the first row of the excel file
    dataFile.close();
  }
}
void Initialize_RTC()

{
   
  rtc.begin();
//#### The following lines can be uncommented to set the date and time for the first time###  

// rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
// rtc.setTime(21, 46, 45);     // Set the time to 12:00:00 (24hr format)
// rtc.setDate(2,12,2020);   // Set the date to 1st January, 2014 


}
void Read_DHT11()
{
int chk = DHT.read11(DHT11_PIN);
}
void Read_DateTime()
{  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  // Send time
  Serial.println(rtc.getTimeStr());
  delay(1000);
}
void Read_TempHum()
{
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
// EE3600 / 3700 Design-III
