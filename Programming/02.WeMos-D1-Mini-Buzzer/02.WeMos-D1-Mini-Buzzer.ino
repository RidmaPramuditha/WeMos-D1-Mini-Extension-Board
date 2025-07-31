/*
  WeMos D1 Mini buzzer

  This example shows how to buzzer
  The circuit:
  buzzer attached to WeMos D1 Mini Extension Board as follows:
 ** Buzzer Positive - pin D5 (GPIO 14)

  created   March 2025
  by P.R. Pramuditha

*/

void setup() {
  pinMode(14, OUTPUT);
}

void loop() {
  digitalWrite(14, HIGH);
  delay(1000);
  digitalWrite(14, LOW);
  delay(1000);
}
