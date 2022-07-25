
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define NAME "omar"
#define PASS "omar@0000"
const byte numChars = 39;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;
bool connected = false;
String pay;
String payload;  
int httpCode;
HTTPClient http;  //Declare an object of class HTTPClient

String URL ="http://192.168.43.251:5000/sendData";


void setup() {
  Serial.begin(9600);
  WiFi.begin(NAME, PASS);
  //Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  //Serial.println("Connected");
  pinMode(BUILTIN_LED, OUTPUT);  
  digitalWrite(BUILTIN_LED, HIGH);
}

void loop() {
 //delay(1000);
 recvFromArduino();
 delay(100);
 Serial.println(receivedChars);
 WiFiClient wifi;
 http.begin(wifi,URL); //Specify request destination
 http.addHeader("Content-Type", "application/json");
 int httpResponseCode = http.POST(receivedChars);
 pay = http.getString();
 http.end();   //Close connection
 if(pay == "1")
 Serial.println("1");
 else
 Serial.println("0");
}

void recvFromArduino() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  while (Serial.available() > 0 ) {
    rc = Serial.read();
    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}
