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

const int button = 15;
const int led = 2;
int buttonState = 0;

void  setup()
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void  loop()
{
  buttonState = digitalRead(button);
  if (buttonState == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led,  LOW);
  }
}
