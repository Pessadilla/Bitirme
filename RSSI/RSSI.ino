#include <ESP8266WiFi.h>

// WiFi ağı bilgileri
const char* ssid1 = "NodeMCU01";
const char* ssid2 = "NodeMCU02";
const char* ssid3 = "NodeMCU03";

// RSSI değerleri
int rssi1 = 0;
int rssi2 = 0;
int rssi3 = 0;

void setup() {
  Serial.begin(115200);

  // Wi-Fi modülü başlatma
  WiFi.mode(WIFI_STA);
}

void loop() {
  // Kablosuz ağları tarama
  WiFi.scanNetworks();
  // RSSI değerlerini ölçme
  for (int i = 0; i < WiFi.scanComplete(); i++) {
    String ssid = WiFi.SSID(i);
    if (ssid == ssid1) {
      rssi1 = WiFi.RSSI(i);
      Serial.print("RSSI1: ");
      Serial.println(rssi1);
    }
    if (ssid == ssid2) {
      rssi2 = WiFi.RSSI(i);
      Serial.print("RSSI2: ");
      Serial.println(rssi2);
    }
    if (ssid == ssid3) {
      rssi3 = WiFi.RSSI(i);
      Serial.print("RSSI3: ");
      Serial.println(rssi3);
    }
  }
  delay(1000);
}