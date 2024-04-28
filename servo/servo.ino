#include <Servo.h>

Servo servo;
int angle = 10;

void setup() {
  servo.attach(0);
  servo.write(angle);
}

void loop(){
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);

}