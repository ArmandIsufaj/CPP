// EE3600 / 3700 Design-III
int trig = 2;
int echo = 3; 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  
//Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);

lcd.init();  
lcd.backlight(); 

}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);


int duration = pulseIn(echo, HIGH);

int distance = (duration/2) / 29.1;

lcd.setCursor(0,0);                // Set the location at which text will be displayed. lcd.setCursor(col, row)
lcd.print("Distance:");               

//Serial.println(distance);
lcd.setCursor(0,1);                // Set the location at which text will be displayed. lcd.setCursor(col, row)
lcd.print(distance);        
lcd.print("cm");
lcd.setCursor(0,2);
lcd.print(distance/2.54);          // 1 inch = 2.54 cm   
lcd.print("Inches");
//Serial.println(distance);

delay(500);
lcd.clear();

}
// EE3600 / 3700 Design-III
