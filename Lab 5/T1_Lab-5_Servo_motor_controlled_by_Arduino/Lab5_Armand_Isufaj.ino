// EE3600 / 3700 Design-III

// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 11

// Create a variable to store the servo position:
int angle = 0;


// Ultrasonic Sensor

int trig = 7;
int echo = 6; 



void setup()  {

// Attach the Servo variable to a pin:
myservo.attach(servoPin);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
 

}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);


int duration = pulseIn(echo, HIGH);

int distance = (duration/2) / 29.1;

if (distance <= 20){
  // Sweep from 0 to 180 degrees:
  for (angle ; angle <= 180; angle += 2) {
    if (distance > 20) break;
  myservo.write(angle);
  
  delay(15);  
  }

  
  // And back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle -= 2) {
  if (distance > 20) break;
  myservo.write(angle);
  delay(15);  
  }
  }
  }

// EE3600 / 3700 Design-III
