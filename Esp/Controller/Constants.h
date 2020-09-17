//Global
//---Include
#include <ESP8266WiFi.h>
//---Values
const char *ssid = "bridgePisquoOS";
const char *password = "testBridge1";
//---Functions
void setup_wifi() {

  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

//Time Module
//---Include
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Timezone.h>
#include <time.h>
//---Values
const long utcOffsetInSeconds = 3600;
int curTime[3];

int alarm[] = {00,00};
bool alarm_active  = false;
bool lock = false;

const TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 60};     // Central European Summer Time
const TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 0};    
Timezone CE(CEST, CET);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "it.pool.ntp.org", utcOffsetInSeconds);

//Alarm Module
//---Pins

/* const int */ #define alarmPin  D1
/* const int */ #define interruptPin  D2

//MQTT
//---Includes
#include <PubSubClient.h>
//---Pins
//---Values
const char* mqtt_server = "mqtt.atrent.it";
char print_msg[200];

WiFiClient mqtt_wifi;
PubSubClient client_mqtt(mqtt_wifi);

//Serial Module
//---Includes
#include <SoftwareSerial.h>
//---Pins
#define txPin D5
#define rxPin D6
//---Values
SoftwareSerial s(txPin, rxPin);
bool sendCom = false;
String comMsg = "";

//Http
//---Includes
#include <ESP8266HTTPClient.h>
//---Values
WiFiClient http_wifi;
HTTPClient http;
String website  = "http://192.168.1.20:8080/update.php";
