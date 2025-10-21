#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "Your Wi-Fi name"; 
const char* password = "Wi-Fi password"; 
int val;
int pin = A0; 
WiFiClient client;
unsigned long myChannelNumber = 'channel number (int)'; 
const char* myWriteAPIKey = "your API key from thinkspeak"; 

void setup() {
    Serial.begin(9600);
    delay(10);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    ThingSpeak.begin(client);
}
void loop() {
    val = (analogRead(pin) * 3.3 / 1024.0) * 100; 
    Serial.print("Temperature: ");
    Serial.print(val);
    Serial.println(" *C");
    int response = ThingSpeak.writeField(myChannelNumber, 1, val, myWriteAPIKey);
    if (response == 200) {
        Serial.println("Data sent to ThingSpeak successfully!");
    } else {
        Serial.print("Error sending data. HTTP Code: ");
        Serial.println(response);
    }
    delay(15000);
}
