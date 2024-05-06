/* This code works with DS3231 RTC module and OLED display
 * It shows a format of date and time in the OLED screen and some cases the temperature too
 * Refer to www.Surtrtech.com for more details
 * This is Code #7 of the tutorial 
 */

#include <SPI.h> //i2c and the display libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>


//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
Adafruit_SSD1306 display(OLED_RESET);
DS3231 clock;
RTCDateTime dt;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  clock.begin();
  delay(1000); 
  display.clearDisplay();
  display.display();
}

void loop() {          //This code displays the Time( Hours:Minutes) as 12h format with (AM/PM) and Date(day of the week/Month/Day of the month)
                       //And the temperature in Fahrenheit
  
  dt = clock.getDateTime();

  display.clearDisplay();
  display.setTextSize(3);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,10);      //position from where you want to start writing           
  display.print(clock.dateFormat("g:i", dt)); //text todisplay
  display.setTextSize(1);
  display.setCursor(60,1);
  display.print(clock.dateFormat("A", dt));
  display.setCursor(95,1);
  display.print(clock.dateFormat("D", dt));
  display.setCursor(95,10);
  display.print(clock.dateFormat("Mj", dt));
  display.setCursor(95,20);
  float c=(clock.readTemperature() * 1.1) - 4; //Temperature is read in C and we convert it to F
  display.print(c,0);
  display.print(" C");
  display.display();
  delay(1000);
}
