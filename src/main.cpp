#include <time.h>
#include <WiFi.h>
#include "MySSID.h"
#include "LGFX_LOLIN32_SSD1306.hpp"

const char ntpServername[] = "ntp.nict.jp";
const long gmtOffset_sec = 3600L*9;
const int daylightOffset_sec = 0;
char timeStr[10];

static LGFX lcd;

struct tm timeinfo;
void PrintTime();

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.setFont(&fonts::lgfxJapanGothic_32);
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
  strftime(timeStr, 9, "%H:%M:%S", &timeinfo);
  lcd.setCursor(0, 0);
  lcd.print(timeStr);
}
