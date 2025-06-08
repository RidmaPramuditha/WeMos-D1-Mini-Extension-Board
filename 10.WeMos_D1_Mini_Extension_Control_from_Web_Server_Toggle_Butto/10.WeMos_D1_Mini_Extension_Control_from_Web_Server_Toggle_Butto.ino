/*
  WeMos D1 Mini Extension Control from Web Server Toggle Button

  This example shows WeMos D1 Mini Extension Control from Web Server Toggle Button
  The circuit:
  LED attached to WeMos D1 Mini Extension Board as follows:
 ** LED Anode - pin D4 (GPIO 2)

  created   June 2025
  by P.R. Pramuditha

*/
#include <ESP8266WiFi.h>

int state = LOW;
int LED = 2;
char on = LOW;
char off = HIGH;

const char* ssid = "";//your-ssid
const char* password = "";//your-password

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, off);

  Serial.print("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  
  server.begin();  // Starts the Server
  Serial.println("Server started");

  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  
  if(request.indexOf("/LEDON") != -1)
  {
    digitalWrite(LED, on); // Turn ON LED
    state = on;
  }
  if(request.indexOf("/LEDOFF") != -1)
  {
    digitalWrite(LED, off); // Turn OFF LED
    state = off;
  }

/*------------------HTML Page Creation---------------------*/

  client.println("HTTP/1.1 200 OK"); // standalone web server with an ESP8266
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head>");
  client.println("<title>LED TOGGLE</title>");
  client.println("</head>");
  client.print("<body>");
  client.println("<header id=\"main-header\">");
  client.println("<h1>LED TOGGLE</h1>");
  client.println("<h4>Onsenss</h4>");
  client.println("</header>");
   
  if(state == on)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.print("<br>");
  client.print("<br>");
  client.println("<a href=\"/LEDON\"\"><button class=\"button\">ON</button></a>");
  client.println("<a href=\"/LEDOFF\"\"><button class=\"button\">OFF</button></a>");
  client.print("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
