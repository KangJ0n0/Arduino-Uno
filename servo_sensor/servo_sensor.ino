#include<Servo.h>
Servo servosatu;
long jarak;
long waktu;


void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  servosatu.attach(10);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13,LOW);
  delayMicroseconds(2);
  digitalWrite(13,HIGH);
  delayMicroseconds(10);
  digitalWrite(13,LOW);

  waktu =pulseIn(12,HIGH);
  jarak=0.034/2*waktu;

if(jarak<20){
  servosatu.write(180);

}
if(jarak>20){
  servosatu.write(0);
 
}

  Serial.print(jarak);

}
