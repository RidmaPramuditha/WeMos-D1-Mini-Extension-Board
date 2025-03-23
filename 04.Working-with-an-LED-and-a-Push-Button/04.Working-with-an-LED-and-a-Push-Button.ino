/*
  WeMos D1 Mini Working with an LED and a Push Button

  This example shows how to Working with an LED and a Push Button
  The circuit:
  LED attached and Push Button to WeMos D1 Mini Extension Board as follows:
 ** LED Anode - pin D4 (GPIO 2)
 ** Push Button - pin D8 (GPIO 15)


  created   March 2025
  by P.R. Pramuditha

*/

const int BUTTON = 15;
const int LED = 2;
int BUTTONstate = 0;

void  setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void  loop()
{
  BUTTONstate = digitalRead(BUTTON);
  if (BUTTONstate == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED,  LOW);
  }
}
