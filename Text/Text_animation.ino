#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int screenWidth = 20;
int screenHeight = 4;
  byte customChar[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01011,
  B11011,
  B11000,
  B00000
};
String line1 = "now playing ";
String line2 = "Seven (feat. Latto) - Clean Ver.";
int stringStart, stringEnd = 0;
int scrollCursor = screenWidth;
LiquidCrystal_I2C lcd(0x27, screenWidth, screenHeight);
void setup() {
  lcd.begin(screenWidth, screenHeight);
  lcd.createChar(0, customChar);
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(12, 0);
  lcd.write(0);
  lcd.setCursor(scrollCursor, 1);
  lcd.print(line2.substring(stringStart,stringEnd));
  delay(400);
  lcd.clear();
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringEnd++;
  }
  else if (stringStart == stringEnd){
    stringStart = stringEnd = 0;
    scrollCursor = screenWidth;
  } 
  else if (stringEnd == line1.length() && scrollCursor == 0) {
    stringStart++;
  } 
  else {
    stringStart++;
    stringEnd++;
  }
}
