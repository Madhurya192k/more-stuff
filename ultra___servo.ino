
#include <Servo.h>
Servo myservo; 

const int trigPin = 11;
const int echoPin = 10;
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(6);
 }
long duration, distance;

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  if(distance<30)
    {
      myservo.write(0);
      delay(1);
    }
    
  else
    {
      myservo.write(180);
    }  
  delay(1);
}
