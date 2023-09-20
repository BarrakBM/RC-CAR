//Arduino Bluetooth Controlled Car
//Before uploading the code you have to install the necessary library
//Note - Disconnect the Bluetooth Module before hiting the upload button otherwise you'll get compilation error message.
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install 
//After downloading the library open Arduino IDE >> go to sketch >> Include Libray >> ADD. ZIP Libray >> Select the downloaded 
//ZIP File >> Open it >> Done
//Now You Can Upload the Code without any problem but make sure the bt module isn't connected with Arduino while uploading code

#include <AFMotor.h>

//initial motors pin
const int EAPin = 3;
const int MAPin = 6;
const int EBPin = 4;
const int MBPin = 5;
const int ECPin = 7;
const int MCPin = 10;
const int EDPin = 8;
const int MDPin = 9;

//Light variables
int led1 = 11;
int led2 = 2;
int led3 = 12;
int led4 = 13;

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.

  //Lights
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led4, OUTPUT);
  //Motors
  pinMode(EAPin,OUTPUT);
  pinMode(MAPin,OUTPUT);
  pinMode(EBPin,OUTPUT);
  pinMode(MBPin,OUTPUT);
  pinMode(ECPin,OUTPUT);
  pinMode(MCPin,OUTPUT);
  pinMode(EDPin,OUTPUT);
  pinMode(MDPin,OUTPUT);
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stopped
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;

    //Lights Code
    case 'W': //Front lights on
      frontLightOn();
      break;
    case 'w': //Front lights off
      frontLightOff();
      break;
    case 'U': //Back lights on
      backLightOn();
      break;
    case 'u': //Back lights off
      backLightOff();
      break;
    }
  } 
}

void forward()
{
  digitalWrite(EAPin,HIGH);
  analogWrite(MAPin,100); 
  digitalWrite(EBPin,LOW);
  analogWrite(MBPin,100);
  digitalWrite(ECPin,HIGH);
  analogWrite(MCPin,100);
  digitalWrite(EDPin,HIGH);
  analogWrite(MDPin,100);
}

void back()
{
  digitalWrite(EAPin,LOW);
  analogWrite(MAPin,100);
  digitalWrite(EBPin,HIGH);
  analogWrite(MBPin,100);
  digitalWrite(ECPin,LOW);
  analogWrite(MCPin,100);
  digitalWrite(EDPin,LOW);
  analogWrite(MDPin,100);
}

void left()
{
  digitalWrite(EAPin,HIGH);
  analogWrite(MAPin,100); 
  digitalWrite(EBPin,HIGH);
  analogWrite(MBPin,100);
  digitalWrite(ECPin,HIGH);
  analogWrite(MCPin,100);
  digitalWrite(EDPin,LOW);
  analogWrite(MDPin,100);
}

void right()
{
  digitalWrite(EAPin,LOW);
  analogWrite(MAPin,100); 
  digitalWrite(EBPin,LOW);
  analogWrite(MBPin,100);
  digitalWrite(ECPin,LOW);
  analogWrite(MCPin,100);
  digitalWrite(EDPin,HIGH);
  analogWrite(MDPin,100);
} 

void Stop()
{
  analogWrite(MAPin,0);
  analogWrite(MBPin,0);
  analogWrite(MCPin,0);
  analogWrite(MDPin,0);
}

void frontLightOn(){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
}

void frontLightOff(){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
}

void backLightOn(){
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
}

void backLightOff(){
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
}