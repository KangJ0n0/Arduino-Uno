float voltage;
float pHValue;
//deklarasi pin analog
int adcPH;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
adcPH = analogRead(4); //menggunakan pin D4 untuk membaca output sensor pH
voltage = adcPH *5.0/1022;
pHValue = (6.4516*voltage)-5.7742;
Serial.print("sensor ph : ");
Serial.println(pHValue);
Serial.print("sensor ph : ");
Serial.print(pHValue);
delay(1000);
}
