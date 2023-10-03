// EE3600 / 3700 Design-III
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);

// pins
const int start = 2;  // create start button that attach to pin 7;
const int reset = 7;  // create reset button that attach to pin 8;
const int data = A0;    // Heart Beat Sensor connected to analogue pin 0

int time1 = 0;
int time2 = 0;
int fpt = 0; // five pulse time
int spt = 0; // single pulse time
int rate = 0;   // create rate

int startState = 0; // value of start pin either high or low
int resetState = 0; // reset pin value, high or low
int k = 0;      // Create counter


byte heart[8] = 
 {
   0b00000,
   0b01010,
   0b11111,
   0b11111,
   0b11111,
   0b01110,
   0b00100,
   0b00000
 };

void setup ( )
{
pinMode(start,INPUT);
pinMode(reset,INPUT);
pinMode(data,INPUT);

lcd.init();  //initialize the lcd
lcd.backlight();  //open the backlight   

lcd.begin(20,4);
lcd.createChar(1,heart);
lcd.clear();
lcd.write(1);
lcd.setCursor(5,0);
lcd.print("Monitering"); 
}

void loop()
 {

  startState = digitalRead(start);
  resetState = digitalRead(reset);
  if(startState == HIGH)  //if((startVal == LOW))                       // check the start button is pressed or not
   {
     lcd.clear();
     lcd.print("Please wait......."); 
     delay(1000); 
      
     while(k<45)
     {lcd.print("n");
      delay(1000);
      if(digitalRead(data))
      {lcd.print("y");
        if(k==0)
        time1=millis();
        k++;
        // while(analogRead(data));
       }
      }
    
   // applying the formula for calculating the heart beat

     time2 = millis();  
     fpt = time2 - time1;
     spt = fpt/45;
     rate = 60000/spt;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Heart Rate:");         
     lcd.setCursor(0,1);                    // setting the cursor at start

     lcd.print(rate);  
   } 
   if(resetState == HIGH)  // check reset button is pressed or not
   {
     rate=0;
      lcd.clear();   
      lcd.setCursor(0,1);                            
      lcd.print("Heart Beat Rate:");         
      lcd.setCursor(0,2);                    // setting the cursor at start
      lcd.write(1);
      lcd.print(rate);                       
       k=0;
       
       }
 }
 // EE3600 / 3700 Design-III
