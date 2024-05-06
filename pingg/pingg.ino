#include <WiFi.h>
#include <ESP32Ping.h>

const char *ssid     = "xxxxxxxxx";
const char *password = "xxxxx";

const char* remote_host = "www.google.com";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

}

void loop() {
  if(Ping.ping(remote_host)) {
    Serial.print(Ping.averageTime());
    Serial.println(" ms");
  } else {
    Serial.println("Error :(");
  }

  delay(100);
  }
