#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> //Creates a client that can connect to to a specified internet IP address and port as defined in client.connect().
#include <ThingSpeak.h>
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "XXXXXXXXXXX";      // Your Mobile Hotspot Name
const char* password = "XXXXXXXXXXX";  // Your Mobile Hotspot Password

WiFiClient client; // created client object

unsigned long myChannelNumber = xxx232x; // Your ThingSpeak Channel Number
const char * myWriteAPIKey = "xxxxxxxxx"; // You ThingSpeak API Key
uint8_t temperature, humidity;

int state=1;
void setup()
{
Serial.begin(115200);
dht.begin();
delay(10);
// Connect to WiFi network
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
// Print the IP address
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}
void loop()
{

//static boolean data_state = false;
temperature = dht.readTemperature();
humidity = dht.readHumidity();
Serial.print("Temperature Value is :");
Serial.print(temperature);
Serial.println("C");
Serial.print("Humidity Value is :");
Serial.print(humidity);
Serial.println("%");

// Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
// pieces of information in a channel. Here, we write to field 1.
if (state==1) {
ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
state = state+1;
Serial.println(state);
Serial.println("Channel 1 transmitted");
}

else if ( state == 2){

ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
state=state+1;
Serial.println(state);
Serial.println("Channel 2 transmitted");
state=1;
}

Serial.println(state);
delay(3000);
}
