// EE3600 / 3700 Design-III
int led1 = 7; 
int led2 = 4; 
void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
 
}

void loop() {
for (int i=0; i<4; i++){
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, LOW);  
  delay(500); 
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(500); 
  }
digitalWrite(led2, LOW);
 
delay(750);

for (int i=0; i<3; i++){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(250); 
  }
  
delay(500);

for (int i=0; i<3; i++){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(750);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(250); 
  }
delay(500);

for (int i=0; i<3; i++){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(250); 
  }
delay(750);
}
// EE3600 / 3700 Design-III
