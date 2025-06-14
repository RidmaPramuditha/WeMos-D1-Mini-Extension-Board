/*
  WeMos D1 Mini Extension Board DHT11

  This example shows WeMos D1 Mini Extension Board DHT11 
  The circuit:
  Relay attached to WeMos D1 Mini Extension Board as follows:
  ** DHT11 Signal pin - pin D7 (GPIO 13)

  created   June 2025
  by P.R. Pramuditha

*/
#include <DHT.h>
#include <ESP8266WiFi.h>

// replace with your channel’s thingspeak API key and your SSID and password
String apiKey = "";
const char* ssid = "";
const char* password = "";
const char* server = "";

#define DHTPIN D7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  delay(10);
  dht.begin();

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop()
{

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (client.connect(server, 80)) {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(t);
    postStr += "&field2=";
    postStr += String(h);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" degrees Celsius Humidity: ");
    Serial.print(h);
    Serial.println("Sending data to Thingspeak");
  }
  client.stop();

  Serial.println("Waiting 20 secs");
  // thingspeak needs at least a 15 sec delay between updates
  // 20 seconds to be safe
  delay(20000);
}
