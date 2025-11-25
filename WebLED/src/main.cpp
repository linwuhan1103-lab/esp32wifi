#include <Arduino.h>
#include <WebServer.h>

// const char *ssid = "i14Max";
// const char *password = "13642375484";
const char *ssid = "wdawu";
const char *password = "ls2221wide";

WebServer server(80);
const byte LED = 2;

void handleRoot() 
{
  // server.send(200,"text/html; charset=UTF-8", "Hello Word");
  String HTML ="<a href=\"/on\">開啟 LED</a> <br>";
  HTML += "<a href=\"/off\">關閉 LED</a>";
  server.send(200,"text/html; charset=UTF-8", HTML);
}

void handleLedOn() 
{
  digitalWrite(LED, HIGH);
  server.send(200,"text/html; charset=UTF-8", "開啟 LED<br><a href=\"/off\">關閉 LED</a>");
}

void handleLedOff() 
{
  digitalWrite(LED, LOW);
  server.send(200,"text/html; charset=UTF-8", "<a href=\"/on\">開啟 LED</a><br>關閉 LED");
}

void handleNotFount()
{
  server.send(404,"text/plain; charset=UTF-8", "not find file - 找不到檔案");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  pinMode(LED, OUTPUT);

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

  server.on("/",handleRoot);
  server.on("/on",handleLedOn);
  server.on("/off",handleLedOff);
  server.onNotFound(handleNotFount);
  server.begin();
  Serial.println("Server is running...");
}

void loop() {
  server.handleClient();
}