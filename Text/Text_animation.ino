#include <LiquidCrystal_I2C.h>

int screenWidth = 20;
int screenHeight = 4;
uint8_t speaker[] = {0x01, 0x03, 0x07, 0x1f, 0x1f, 0x07, 0x03, 0x01};
String line1 = "now playing ";
String line2 = "Seven (feat. Latto) - Clean Ver.";
String line3 = "Jung Kook";
int stringStart, stringEnd = 0;
int scrollCursor = screenWidth;
LiquidCrystal_I2C lcd(0x27, screenWidth, screenHeight);
void setup() {
  lcd.begin(screenWidth, screenHeight);
  lcd.createChar(0, speaker);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.write(byte(0));
  lcd.setCursor(0, 2);
  lcd.print(line3);
  lcd.setCursor(scrollCursor, 1);
  lcd.print(line2.substring(stringStart,stringEnd));
  delay(500);
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
