#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP("NodeMCU03","12345678");
}

void loop() {
  // put your main code here, to run repeatedly:

}
