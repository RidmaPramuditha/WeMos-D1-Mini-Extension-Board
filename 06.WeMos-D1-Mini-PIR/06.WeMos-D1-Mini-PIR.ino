/*
  WeMos D1 Mini and PIR Sensor

  This example shows how to working PIR Sensor
  The circuit:
  NeoPixel LED attached to WeMos D1 Mini Extension Board as follows:
  ** Buzzer Positive - pin D5 (GPIO 14)
  ** PIR Signal- pin D7 (GPIO 13)
  ** PIR GND - WeMos D1 Mini Extension GND
  ** PIR VCC - WeMos D1 Mini Extension 5V

  created   June 2025
  by P.R. Pramuditha

*/
int pirPin = 13;
int sound = 14;
int val;

void setup()
{
  Serial.begin(9600);
  pinMode(sound, OUTPUT);
}

void loop()
{
  val = digitalRead(pirPin);
  //low = no motion, high = motion
  if (val == LOW)
  {
    Serial.println("No motion");
    digitalWrite(sound, LOW);
    delay(1000);

  }
  else
  {
    Serial.println("Motion detected  ALARM");
    digitalWrite(sound, HIGH);
    delay(1000);
  }

  delay(1000);
}
