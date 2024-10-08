#include <Servo.h>

//pines del pueste h
int ENA = 5;
int IN1 = 7;
int IN2 = 6;
int ENB = 3;
int IN3 = 4;
int IN4 = 2; 

Servo tservo;

//Pines del sensor ultrasonico 
int  trig = 9;
int  echo = 10;
int time;
int distance;

Servo Aservo; 

void setup(){

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 
  
  tservo.attach(8);
  Aservo.attach(11);
  Serial.begin(9600);

}

void loop() {
  //servosonico 
  digitalWrite(trig, HIGH);
  delayMicroseconds(25);
  digitalWrite(trig, LOW);
  time=pulseIn(echo, HIGH);
  distance=time/58.2; 
  delay(10); 
  digitalWrite(trig, LOW);
  Serial.println(time);

  //Avanzar 
  analogWrite(ENA,103);
  analogWrite(ENB,100);
  tservo.write(94);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  //girara a la derecha 
  if(distance <= 20) {
  analogWrite(ENA,53);
  analogWrite(ENB,50);
  tservo.write(120);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);
  }
}