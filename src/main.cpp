#include <Arduino.h>
#include <time.h>
#include <WiFi.h>
#include <SSD1306Wire.h>
#include "MySSID.h"
#include "font.h"

static const char ntpServername[] ="ntp.nict.jp";
const long gmtOffset_sec = 3600L*9;
const int daylightOffset_sec = 0;

SSD1306Wire display(0x3c, 5, 4);

struct tm timeinfo;
void PrintTime();

void setup() {
  Serial.begin(9600);
  display.init();
  display.setFont(Roboto_Mono_Medium_25);
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(50);
  }
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServername);
  PrintTime();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  delay(100);
  PrintTime();
}

void PrintTime(){
  getLocalTime(&timeinfo);
  display.setLogBuffer(5, 30);
  display.clear();
  display.println(&timeinfo,"%H:%M:%S");
  display.drawLogBuffer(0, 0);
  display.display();
}
