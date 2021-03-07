#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"

/*******************************************

Setup
  Connect to wifi
  setup ntp(?)

Loop 
  handleClient


on page Load
get last slider values
  for each slide ready
    set slider value 

onchange of element
 element_change  (element changed, val)
  new http request
  param.set(element, val)
  send request



Server side C++
===========================================

handlePWM
  switch server.argName()
  case 'PWM1':
    analogwrite pin_name , pin value
    break;
  case 'PWM2' :
  case 'PWM3' :
  case 'PWM4' :


fade(start, end, duration)


sendSlider
  return slider value as response


******************************/


 
//SSID and Password of your WiFi router
const char* ssid = "jbnet_IoT";
const char* password = "3441Josh&Babak#1119";

ESP8266WebServer server(80);
 
#define PWM1_pin 5  //D1
#define PWM2_pin 4  //D2
#define PWM3_pin 0  //D3
#define PWM4_fan 12 //D6
#define tach_pin 14 //D5

void handlePWM() {

  String PWM1_val = server.arg("PWM1_val");
  String PWM2_val = server.arg("PWM2_val");
  String PWM3_val = server.arg("PWM3_val");
  String PWM4_val = server.arg("PWM4_val");

  analogWriteFreq(500);
  analogWrite(PWM1_pin,PWM1_val.toInt()); // chaning the value on the NodeMCU board
  analogWrite(PWM2_pin,PWM2_val.toInt()); // chaning the value on the NodeMCU board
  analogWrite(PWM3_pin,PWM3_val.toInt()); // chaning the value on the NodeMCU board
  analogWrite(PWM4_fan,PWM4_val.toInt()); // chaning the value on the NodeMCU board

  server.send(200,"text/plain","0"); // handling the webpage update

}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
    delay(500);
    Serial.println("Waiting to connect?");
  }
 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP

  server.on("/", handleRootPath);    //Associate the handler function to the path
  server.on("/setPWM", handlePWM);   // handles the PWM values
  server.on("/getSlider",getSlider);
  server.begin();                    //Start the server
  Serial.println("Server listening");

  analogWriteFreq(500);
  analogWrite(PWM1_pin,0); // chaning the value on the NodeMCU board
  analogWrite(PWM2_pin,0); // chaning the value on the NodeMCU board
  analogWrite(PWM3_pin,0); // chaning the value on the NodeMCU board
  analogWrite(PWM4_fan,0); // chaning the value on the NodeMCU board
 
}
 
void loop() {
 
  server.handleClient();         //Handling of incoming requests
 
}
 
void handleRootPath() {            //Handler for the rooth path
  server.send(200, "text/html", html_page, sizeof(html_page) );
 
}
