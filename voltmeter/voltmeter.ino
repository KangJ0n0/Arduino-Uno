int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 10000.0; // resistance of R1 (100K)
float R2 = 1000.0; // resistance of R2 (10K)
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
} 
Serial.println(vin);
delay(500);
}
