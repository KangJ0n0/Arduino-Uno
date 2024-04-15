#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int screenWidth = 20;
int screenHeight = 4;
int i=0;
int j=0;
int randomnum;
int k=0;
byte customChar1[] = {
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E
};

byte customChar2[] = {
  0x00,
  0x00,
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E,
  0x0E
};
byte customChar3[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x0E,
  0x0E,
  0x0E,
  0x0E
};
byte customChar4[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x0E,
  0x0E
};
byte customChar5[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};
String line1 = "now playing : ";
String line2 = "Seven (feat. Latto) - Band Ver.";
int stringStart, stringEnd = 0;
int scrollCursor = screenWidth;
LiquidCrystal_I2C lcd(0x27, screenWidth, screenHeight);
void setup() {
  lcd.begin(screenWidth, screenHeight);
  lcd.createChar(4, customChar1);
  lcd.createChar(3, customChar2);
  lcd.createChar(2, customChar3);
  lcd.createChar(1, customChar4);
  lcd.createChar(0, customChar5);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(scrollCursor, 1);
  lcd.print(line2.substring(stringStart,stringEnd));
  delay(400);
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
   randomnum=random(7,9);
  Serial.print ("random numer = ");
  Serial.println (randomnum);
  
for (i=randomnum ; i>0; i--)
 {
 int z=i;
  Serial.print ("i value = ");
  Serial.println (i);
  Serial.print ("j= ");
  Serial.println (j);
  Serial.print ("k= ");
  Serial.println (k);
    test();
    lcd.setCursor(10,2);
    lcd.write(j);
    lcd.setCursor(10,3);
    lcd.write(k);
    i--;
    test();
    lcd.setCursor(11,2);
    lcd.write(j);
    lcd.setCursor(11,3);
    lcd.write(k);
    lcd.setCursor(9,2);
    lcd.write(j);
    lcd.setCursor(9,3);
    lcd.write(k);
     i--;
    test();
    lcd.setCursor(12,2);
    lcd.write(j);
    lcd.setCursor(12,3);
    lcd.write(k);
    lcd.setCursor(8,2);
    lcd.write(j);
    lcd.setCursor(8,3);
    lcd.write(k);

    i--;
    test();
    lcd.setCursor(13,2);
    lcd.write(j);
    lcd.setCursor(13,3);
    lcd.write(k);
    lcd.setCursor(7,2);
    lcd.write(j);
    lcd.setCursor(7,3);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(14,2);
    lcd.write(j);
    lcd.setCursor(14,3);
    lcd.write(k);
   lcd.setCursor(6,2);
    lcd.write(j);
    lcd.setCursor(6,3);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(15,2);
    lcd.write(j);
    lcd.setCursor(15,3);
    lcd.write(k);
   lcd.setCursor(5,2);
    lcd.write(j);
    lcd.setCursor(5,3);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(16,2);
    lcd.write(j);
    lcd.setCursor(16,3);
    lcd.write(k);
   lcd.setCursor(4,2);
    lcd.write(j);
    lcd.setCursor(4,3);
    lcd.write(k);

     i--;
    test();
    lcd.setCursor(17,2);
    lcd.write(j);
    lcd.setCursor(17,3);
    lcd.write(k);
   lcd.setCursor(3,2);
    lcd.write(j);
    lcd.setCursor(3,3);
    lcd.write(k);
    
    delay(50);
    clearRow(2);
    clearRow(3);
   
 i=z;
 }
 }

void test()
{

  if (i ==8)
   {
    j= 4;
    k=4;
  }
   if (i ==7)
  {
    j=3;
    k=4;
  }
   if (i ==6)
  {
    j=2;
    k=4;
  }
     if (i ==5)
  {
    j=1;
    k=4;
  }
     if (i ==4)
  {
    j=0;
    k=4;
  }
     if (i ==3)
  {
    j=0;
    k=3;
  }
     if (i ==2)
  {
    j=0;
    k=2;
  }
     if (i ==1)
  {
    j=0;
    k=1;
  }
     if (i ==0)
  {
    j=0;
    k=0;
  }
}
void clearRow(int row) {
  lcd.setCursor(0, row);  // Set kursor ke posisi awal baris yang ingin dihapus
  lcd.print("                    ");  // Mengisi baris dengan spasi untuk menghapus konten
}
