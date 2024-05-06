#include <stdio.h>
#include <stdlib.h>

const int button1 = 9;  //button led 1 AND
const int button2 = 8;  //button led 2 AND
const int led1 = 10; //led 1
const int led2 = 11; //led 2
const int led3 = 12; //led 3


void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if ( digitalRead(button1) == HIGH && digitalRead(button2) == LOW)   //LOGIKA AND
  {
    digitalWrite(led1, HIGH);
  }

  if ( digitalRead(button1) == LOW && digitalRead(button2) == HIGH) 
  {
    digitalWrite(led2, HIGH);
  }
  if (led1 == HIGH || led2 == HIGH)                                   //LOGIKA OR
    { digitalWrite (led3, LOW); }
    else
    { digitalWrite (led3, HIGH); }
}
