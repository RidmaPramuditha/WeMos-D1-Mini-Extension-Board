/*
  WeMos D1 Mini NeoPixel LED

  This example shows how to NeoPixel LED
  The circuit:
  NeoPixel LED attached to WeMos D1 Mini Extension Board as follows:
 ** NeoPixel LED Anode - pin D6 (GPIO 12)

  created   March 2025
  by P.R. Pramuditha

*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN        12
#define NUMPIXELS 1 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 

void setup() {
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
}

void loop() {
  pixels.clear(); 

  for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();  
    delay(DELAYVAL);
  }
}
