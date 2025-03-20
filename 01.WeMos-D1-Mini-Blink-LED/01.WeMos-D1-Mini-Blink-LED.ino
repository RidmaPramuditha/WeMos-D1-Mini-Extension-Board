/*
  WeMos D1 Mini Blink LED

  This example shows how to Blink LED
  The circuit:
  LED attached to WeMos D1 Mini Extension Board as follows:
 ** LED Anode - pin D4 (GPIO 2)

  created   March 2025
  by P.R. Pramuditha

*/

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
}
