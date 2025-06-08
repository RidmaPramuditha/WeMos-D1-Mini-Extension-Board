/*
  WeMos D1 Mini Relay

  This example shows Relay Control 
  The circuit:
  Relay attached to WeMos D1 Mini Extension Board as follows:
  ** Relay - pin D7 (GPIO 13)

  created   June 2025
  by P.R. Pramuditha

*/int relayPin = 13;

void setup() {
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, LOW);
  delay(5000);

  digitalWrite(relayPin, HIGH);
  delay(5000);
}
