#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "SWATI";  // Enter SSID here
const char* password = "8585865764";  //Enter Password here

/* Set  IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t LED1pin = D1;
bool LED1 = LOW;

uint8_t LED2pin = D2;
bool LED2 = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);

//connect to your local wi-fi network
  WiFi.begin(ssid, password);
  delay(100);
  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  
  server.on("/",OnConnect);
  server.on("/led1on",led1on);
  server.on("/led1off",led1off);
  server.on("/led2on",led2on);
  server.on("/led2off",led2off);
  server.onNotFound(NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
  if(LED1)
    digitalWrite(LED1pin, HIGH);
  else
    digitalWrite(LED1pin, LOW);
  
  if(LED2)
    digitalWrite(LED2pin, HIGH);
  else
    digitalWrite(LED2pin, LOW);
}
