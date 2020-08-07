#include <Arduino.h>
#if defined (ARDUINO_ARCH_ESP32)
#include <WiFi.h>
#elif defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>
#else
#	error "include here the wifi header files"
#endif

//include multilog header file
#include "multilog.h"

// instanciate multilog with HW Serial output and UDP broadcast to port 34200, limited to the defined subnet.
MultiLog xMultiLog(IPAddress(192,168,178,255), 34200, &Serial);

//Wifi
const char *ssid = "SSID";
const char *password = "PASSWORD";

void setup() {
  // put your setup code here, to run once:

  //The HW serial interface must be initialized
  Serial.begin(9600);

  //ota and wifi
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);   
  WiFi.begin(ssid, password);
  byte count = 0;
  while(WiFi.status() != WL_CONNECTED && count < 100)
  {
    count ++;
    delay(500);
    xMultiLog.print(".");
  }
  if(WiFi.status() == WL_CONNECTED)
  {    
    // you're connected now, so print out the status:
    xMultiLog.println(" WIFI Connected");
  }    
  else
  {
    xMultiLog.println(" WIFI Connect False, reboot.");
    delay(5000);
    ESP.restart();
  }

  xMultiLog.println("UDP test message.");

}

//timer/delays
#define MAIN_DELAY_TIME 1000  //1 sec
uint TaskCounter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  delay(MAIN_DELAY_TIME);
  TaskCounter++;

  //print the task counter
  xMultiLog.print("Current task counter: ");
  xMultiLog.println(TaskCounter);
}