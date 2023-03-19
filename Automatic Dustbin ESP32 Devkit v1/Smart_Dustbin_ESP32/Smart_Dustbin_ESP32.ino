#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>


#define echopin 15
#define trigpin 2
#define buzz 4

Servo myservo;
long duration, distancecm, distanceinch;
int pos = 0; 
int servoPin = 5;

void setup (){
 
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  myservo.attach(servoPin);
}

void loop(){
    digitalWrite(trigpin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(1);
  
  duration= pulseIn(echopin, HIGH);
  distancecm = duration*0.034/2;
  distanceinch = duration*0.0133/2;
  if (distancecm < 20 ){
    myservo.write(180);
    delay(1000);
    }
   else{
    myservo.write(0);
    delay(1000);
   }
  }

