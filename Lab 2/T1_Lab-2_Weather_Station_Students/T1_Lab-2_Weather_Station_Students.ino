// EE3600 / 3700 Design-III


#include <LiquidCrystal_I2C.h>
#include <dht.h>


LiquidCrystal_I2C lcd(0x27,20,4);     // Creates an lcd object with (i2c address 0x27, 20 columns, 4 rows)
#define DHT11_PIN 7                   // Digital pin connected to the DHT sensor
dht DHT;                              // Set up DHT object from dht library



void setup()
{
  lcd.init();  
  lcd.backlight();  
}

void loop(){
  DHT.read11(DHT11_PIN);             // Reads the DHT11 humidity temperature combo sensor connected to pin DHT11_PIN
  lcd.setCursor(0,0);                // Set the location at which text will be displayed. lcd.setCursor(col, row)
  lcd.print("Temp: ");               
  lcd.print(DHT.temperature);        
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  lcd.setCursor(0,2);
  lcd.print("Group 10 ");
  lcd.setCursor(0,3);
  lcd.print("Date:30.10.2020");

  delay(2000);
}
// EE3600 / 3700 Design-III
