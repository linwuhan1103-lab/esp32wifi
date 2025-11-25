#include <Arduino.h>
#include <WebServer.h>

// const char *ssid = "i14Max";
// const char *password = "13642375484";
const char *ssid = "wdawu";
const char *password = "ls2221wide";


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi Connected.");
  Serial.print("My IP : ");
  Serial.println(WiFi.localIP());

  Serial.print("Submask = ");
  Serial.println(WiFi.subnetMask());

}

void loop() {

}