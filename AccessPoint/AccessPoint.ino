#include <ESP8266WiFi.h>

const char* ssid = "ESP-AP";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);

  // WiFi modülünü başlatma
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("Access Point '");
  Serial.print(ssid);
  Serial.println("' started");
}

void loop() {
  // Bağlı cihazları tarama
  int num_clients = WiFi.softAPgetStationNum();
  Serial.print("Number of clients: ");
  Serial.println(num_clients);

  // Her bir bağlantı için RSSI değerini ölçme
  if (num_clients > 0) {
    Serial.println("Client list:");
    for (int i = 0; i < num_clients; ++i) {
      IPAddress ip = softAP_getStationInfo(i);
      int32_t rssi = WiFi.RSSI(ip);
      Serial.print("IP address: ");
      Serial.print(ip);
      Serial.print(" (RSSI: ");
      Serial.print(rssi);
      Serial.println(")");
    }
  }

  delay(1000);
}