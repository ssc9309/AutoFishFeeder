#include <Servo.h>
#include "Pitch.h"

int servoPin = 5;
int buzzerPin = 8;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  myServo.write(10);
  
  PlaySong();
  MoveServo();
  
  //delay for a day
  //tried doing delay(1000*60*60*24), but it doesn't work.
  //something about 16 bit, bla bla bla
  myServo.write(10);
  for (int x = 0; x < 24; x ++)
  {
    for (int y = 0; y < 60; y++)
    {
      for (int z = 0; z < 60; z++)
      {
        delay(1000);
      }
    }
  }
}

void MoveServo()
{
  int pos = 0;
  for(pos = 10; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);                       // waits 15ms for the servo to reach the position 
  }
}

//Play under the sea
int melody[] = {
  NOTE_D5, NOTE_F5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_F5, NOTE_A5, NOTE_C6, NOTE_AS5, NOTE_F5, 
  NOTE_AS4, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_C5, NOTE_F5, NOTE_DS5, NOTE_D5
};

//4 = quarter note, 8 = eighth note
int noteDurations[] = {
  8,8,8,4,4,8,4,4,4,4,8,8,8,4,4,8,4,4,4
};
void PlaySong()
{
  //there are 19 notes
  for (int thisNote = 0; thisNote < 19; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
}
