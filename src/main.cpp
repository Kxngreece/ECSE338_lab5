#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>
#include"env.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Set pin mode
  Serial.begin(9600); 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  lcd.print("Connecting....");
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.clear();
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
   lcd.print("Connected!!");
  Serial.println(WiFi.localIP());
  lcd.clear();
}

void loop() {
 
  HTTPClient http;

  http.begin(endpoint.c_str());
 http.addHeader("api-key",api_key);
  int httpResponseCode = http.GET();
  

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String responseBody = http.getString();
    Serial.println(responseBody);

  

    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, responseBody);

    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }

 String line_1 = doc["line_1"]; // "Please"
 String line_2 = doc["line_2"]; // "Work"
 lcd.setCursor(0,0);
lcd.print(line_1);
lcd.setCursor(0,1);
lcd.print(line_2);

  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
  delay(4000);
  lcd.clear();
}


