#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#define PIR_PIN D6  // Define your PIR_PIN
#define flame_sensor D5
#define gas_sensor D7

// Wi-Fi credentials
const char* WIFI_SSID = "wifi_name";
const char* WIFI_PASSWORD = "password";

// URL for triggering an alert
const char* CHECK_URL = "https://api.telegram.org/-Enter your Telegram bot API-/sendMessage?chat_id=-ChatID-&text=alert.....someone%20else%20in%20your%20house ";

void setup() {
  Serial.begin(115200);
  
  // Initialize PIR sensor pin
  pinMode(PIR_PIN, INPUT);
  pinMode(flame_sensor,INPUT);
  pinMode(gas_sensor,INPUT);
  // Connect to Wi-Fi
  connectToWiFi();
  
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);
  int flameDetected = digitalRead(flame_sensor);
  int gasDetected = digitalRead(gas_sensor);
  
  if (motionDetected == HIGH) {  // Trigger if motion is detected
    Serial.println("Motion detected!");
    checkUrlAndTrigger();
    //delay(2000);
  } else {
    Serial.println("No motion detected.");
  }
  
  if (flameDetected == LOW){
    Serial.println("Flame Detected!");
    checkUrlAndFlame();
  } else {
    Serial.println("No Flame Detected!");
  }

  if (gasDetected == LOW){
    Serial.println("Gas Detected!");
    checkUrlAndGas();
  } else {
    Serial.println("No gas Detected!");
  }
  delay(100);  // Add a small delay to reduce CPU usage
}

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Wi-Fi connected! IP: ");
  Serial.println(WiFi.localIP());
}



void checkUrlAndTrigger() {
  WiFiClientSecure client;
  client.setInsecure();  // This bypasses SSL certificate verification. It's okay for testing, but avoid in production.

  const char* host = "api.telegram.org";  // Hostname
  const int httpsPort = 443;  // HTTPS port

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection to server failed");
    return;
  }

  // Send the GET request
  String url = "/Enter your Telegram bot API/sendMessage?chat_id=-CHAT ID-&text=alert.....something%20else%20in%20ur%20house";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Wait for the server response
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers received");
      break;
    }
  }

  // Read the response body
  String response = client.readString();
  Serial.println("Response:");
  Serial.println(response);
}

//Flame
void checkUrlAndFlame() {
  WiFiClientSecure client;
  client.setInsecure();  // This bypasses SSL certificate verification. It's okay for testing, but avoid in production.

  const char* host = "api.telegram.org";  // Hostname
  const int httpsPort = 443;  // HTTPS port

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection to server failed");
    return;
  }

  // Send the GET request
  String url = "/Enter your Telegram bot API/sendMessage?chat_id=chatID&text=alert....%20Flame%20is%20Detected";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Wait for the server response
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers received");
      break;
    }
  }

  // Read the response body
  String response = client.readString();
  Serial.println("Response:");
  Serial.println(response);
}

//Gas
void checkUrlAndGas() {
  WiFiClientSecure client;
  client.setInsecure();  // This bypasses SSL certificate verification. It's okay for testing, but avoid in production.

  const char* host = "api.telegram.org";  // Hostname
  const int httpsPort = 443;  // HTTPS port

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection to server failed");
    return;
  }

  // Send the GET request
  String url = "/Enter your Telegram bot API/sendMessage?chat_id=chatID&text=alert.....%20GAS%20is%20Detected!";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Wait for the server response
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers received");
      break;
    }
  }

  // Read the response body
  String response = client.readString();
  Serial.println("Response:");
  Serial.println(response);
}