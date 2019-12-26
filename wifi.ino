#include "ESP8266WiFi.h"

const char* ssid = "Swapnanil"; //Enter SSID
const char* password = "5057530843"; //Enter Password

void setup(void)
  { 
    Serial.begin(9600);
    // Connect to WiFi
    WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) 
    {
       delay(1000);
       Serial.print("*");
    }
    
    Serial.println("");
    Serial.println("WiFi connection Successful");
    Serial.print("The IP Address of ESP8266 Module is: ");
    Serial.print(WiFi.localIP());// Print the IP address
  }
  
  void loop() 
  {
    // EMPTY
  }
