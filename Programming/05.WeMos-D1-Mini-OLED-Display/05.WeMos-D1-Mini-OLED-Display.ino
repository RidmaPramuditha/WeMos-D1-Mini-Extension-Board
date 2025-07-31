/*
  WeMos D1 Mini OLED Display

  This example shows how to working OLED Display

  created   May 2025
  by P.R. Pramuditha

*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {

  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.setCursor(1, 0);
  oled.print("Onsenss");
  oled.setTextSize(2);
  oled.display();

}
