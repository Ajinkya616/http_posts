#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "Airtel_7822864892";
const char* password = "air46235";

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Connected Succesfully");
    WiFiClient wificlient;
    HTTPClient http;
    http.begin(wificlient,"http://jsonplaceholder.typicode.com/users");

    //    http.begin(wificlient, "https://test-nodejs-server-343012.ew.r.appspot.com");
    //    http.addHeader("Content-Type", "application/json");
    //    int httpCode = http.POST("{\"title\":\"Another new book\",\"description\":\"description\",\"unitCost\":23.54,\"isbn\":\"isbn\",\"publicationDate\":\"2012-12-12\",\"nbOfPages\":234,\"imageUrl\":\"imageUrl\",\"language\":\"ENGLISH\"}");

    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST("This is a http post");
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();
  }
  delay(5000);
}
