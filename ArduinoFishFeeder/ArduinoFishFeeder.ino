#include <Servo.h>

int servoPin = 5;
int startButton = 8;
int startFlag = 0;
unsigned long prevTime = 0;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  
  pinMode(startButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(startButton) == HIGH)
  {
    startFlag = 1;
    
  }
}

private void MoveServo()
{
  
}
