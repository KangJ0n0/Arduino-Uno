#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int trigPin = 12;
const int echoPin = 11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
// defines variables
long duration;
int distance;

void setup() 
{
lcd.begin();
lcd.setCursor(0,0);
lcd.print("   CNC STORE");
lcd.setCursor(0,1);
lcd.print("    BANDUNG");
delay (3000);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() 
{
lcd.clear();
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("by:CNC STORE BDG");
  delay (500);
}
