int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;

#include <Servo.h> 

int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int prev1 = 0;
int curr1 = 0;
int prev2 = 0;
int curr2 = 0;
int prev3 = 0;
int curr3 = 0;

int cooldownTime = 5;
int count = 0;

int servoPin = 3; 
Servo Servo1; 


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Servo1.attach(servoPin); 
  
  Servo1.write(0);

}

void loop() {
  curr1 = analogRead(sensorPin1);
  curr2 = analogRead(sensorPin2);
  curr3 = analogRead(sensorPin3);

  Serial.print(curr1);
  Serial.print(curr2);
  Serial.println(curr3);

  if (abs(prev1 - curr1)>50 and count>cooldownTime){  //RIGHTMOST
    Servo1.write(90);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    Servo1.write(0);
    digitalWrite(ledPin, LOW);
    count=0;
    
  }
  if (abs(prev3 - curr3)>50 and count>cooldownTime){
    Servo1.write(180);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    Servo1.write(0);
    digitalWrite(ledPin, LOW);
    count=0;
  }
  if (abs(prev2 - curr2)>50 and count>cooldownTime){
    Servo1.write(90);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    Servo1.write(0);
    digitalWrite(ledPin, LOW);
    count=0;
  }

    prev1 = curr1;
    prev2 = curr2;
    prev3 = curr3;

  delay(500);
  count+=1;
}
