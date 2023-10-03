/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */
// Include the servo library:
#include <Servo.h>
// Create a new servo object:
Servo myservo;
// Define the servo pin:
#define servoPin 11
// Create a variable to store the servo position:
int angle = 0;
void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);

  Serial.begin(9600);
  
}
void loop() {
  
  // Tell the servo to go to a particular angle:
  //myservo.write(90);
  //delay(1000);
  //myservo.write(180);
  //delay(1000);
  //myservo.write(0);
  //delay(1000);
  Serial.println(myservo.read());
  for (angle = myservo.read(); angle >= 0; angle += 1) {
    myservo.write(angle);
    Serial.print(myservo.read());
    delay(15);
  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    Serial.print(myservo.read());
    delay(15);
  }
  // And back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    Serial.print(myservo.read());
    delay(30);
  }
  delay(1000);
}
}
