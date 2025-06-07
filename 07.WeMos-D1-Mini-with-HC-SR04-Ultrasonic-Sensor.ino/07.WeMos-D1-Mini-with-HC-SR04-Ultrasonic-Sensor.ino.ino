/*
  WeMos D1 Mini with HC-SR04 Ultrasonic Sensor

  This example shows how to working OLED Display

  created   June 2025
  by P.R. Pramuditha

*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CommonSenseMetricSystem

#define trigPin 12
#define echoPin 13

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);  //PULSE ___|---|___
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

#ifdef CommonSenseMetricSystem
  distance = (duration / 2) / 29.1;
#endif
#ifdef ImperialNonsenseSystem
  distance = (duration / 2) / 73.914;
#endif

  oled.setCursor(22, 20); //oled display
  oled.setTextSize(3);
  oled.setTextColor(WHITE);
  oled.println(distance);
  oled.setCursor(85, 20);
  oled.setTextSize(3);

#ifdef CommonSenseMetricSystem
  oled.println("cm");
#endif
#ifdef ImperialNonsenseSystem
  oled.println("in");
#endif

  oled.display();

  delay(500);
  oled.clearDisplay();

  Serial.println(distance);//debug



}
