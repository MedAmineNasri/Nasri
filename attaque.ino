#include<Servo.h>
#include <SoftwareSerial.h>
char module;
const int maxspeed = 255;
const int m11  = 3; 
const int m12  = 5;  
const int m21  = 6; 
const int m22  = 9; 
Servo monServo;
int posServo=180;
void setup() {
monServo.attach(11);
monServo.write(posServo);
Serial.begin(9600);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);
}

void loop() {
if (Serial.available()>0) 
   {module=Serial.read();}
if (module == 'O')
{
  for (posServo =180 ; posServo >= 80 ; posServo --)
  {
    monServo.write(posServo);
  delay(20);
  }
}
else if (module == 'F')
{
  for (posServo =80 ; posServo <=180 ; posServo ++)
  {
    monServo.write(posServo);
    delay(20);
  }
}
if (module == 'A')
{
  analogWrite(m11, maxspeed); analogWrite(m12, 0);
        analogWrite(m21, maxspeed);      analogWrite(m22, 0);
}
else if (module == 'R')
{
  analogWrite(m11, 0); analogWrite(m12, maxspeed);
        analogWrite(m21, 0);      analogWrite(m22, maxspeed);
}

else if (module == 'S')
{analogWrite(m11, 0); analogWrite(m12, 0);
        analogWrite(m21, 0);      analogWrite(m22, 0);
}
else if (module == 'D')
{
  analogWrite(m11, maxspeed); analogWrite(m12, 0);
        analogWrite(m21, 0);      analogWrite(m22, 0);
}
else if (module == 'G')
{
  analogWrite(m11, 0); analogWrite(m12, 0);
        analogWrite(m21, maxspeed);      analogWrite(m22, 0);
}
else if (module == 'C')
{
  analogWrite(m11, 0); analogWrite(m12, maxspeed);
        analogWrite(m21, 0);      analogWrite(m22, 0);
}
else if (module == 'W')
{
  analogWrite(m11, 0); analogWrite(m12, 0);
        analogWrite(m21, 0);      analogWrite(m22, maxspeed);
}
}
