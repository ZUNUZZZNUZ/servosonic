#include <Servo.h>

Servo myservo;  

const int trigPin = 10;  
const int echoPin = 9;  
//modifikasi atau copas kontak ZUNUZZZ

void setup() {
  myservo.attach(8);  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  
//modifikasi atau copas kontak ZUNUZZZ

  int servoPosition;

  if (distance <= 10) {
    
    servoPosition = 180;
  } else if (distance > 20) {
    
    servoPosition = 0;
  } else {
    
  }

  
  myservo.write(servoPosition);

//modifikasi atau copas kontak ZUNUZZZ 
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.print(" cm, Posisi Servo: ");
  Serial.println(servoPosition);

  delay(500);  
}
