#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Redmi9";
const char* password = "12345678";

void setup () {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to");
    Serial.println( ssid);
  }
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient wificlient;
    HTTPClient http;
    http.begin(wificlient, "http://jsonplaceholder.typicode.com/users/1");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(5000);
}
