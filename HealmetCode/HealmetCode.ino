#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h"  //Web page header file

#include "DHT.h" 
#define DHTPIN 33     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321 /
DHT dht(DHTPIN, DHTTYPE);


WebServer server(80);

//Enter your SSID and PASSWORD
const char* ssid = "+++++++";
const char* password = "++++++++++";



void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC() {
 
 int a = analogRead(34);
 String adcValue = String(a);
 
 server.send(200, "text/plane", adcValue); //Send ADC value only to client ajax request

}

void temp() {
  
 float t = dht.readTemperature();
 String tempValue = String(t);
 
 server.send(200, "text/plane", tempValue); //Send ADC value only to client ajax request
}

void humi() {
  
 float h = dht.readHumidity();
 String humiValue = String(h);
 
 server.send(200, "text/plane", humiValue); //Send ADC value only to client ajax request
}



void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

   dht.begin();
/*
//ESP32 As access point
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);
*/

  WiFi.mode(WIFI_STA); //Connectto your wifi
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readADC", handleADC);//To get update of ADC Value only
  server.on("/temp", temp);
  server.on("/humi", humi);
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}


void loop(void){
  
  server.handleClient();
  delay(1);
}
