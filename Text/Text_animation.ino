#include <LiquidCrystal_I2C.h>

const int col = 20;
const int row =  4;

int position = 0;
LiquidCrystal_I2C lcd(0x27, col, row);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
  
void loop() {
  lcd.clear();
  position += 1;
  lcd.setCursor(position, 0);
  lcd.print("now playing");
  lcd.setCursor(position, 1);
  lcd.print("少女レイ");
  cd.setCursor(position, 3);
  lcd.print("MORE MORE JUMP !");
 delay(250);

 if(position < 0 || position >= col) {
  position = 0;
 }
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
}
