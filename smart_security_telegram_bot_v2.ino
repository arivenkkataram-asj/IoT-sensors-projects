#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// Define sensor pins
#define PIR_PIN D6  // PIR motion sensor
#define FLAME_SENSOR D5
#define GAS_SENSOR D7

// Wi-Fi credentials
const char* WIFI_SSID = "-----"; //replace with your WiFi name 
const char* WIFI_PASSWORD = "-----"; //Replace with your WiFi Password

// Telegram Bot API details
const char* TELEGRAM_BOT_API = "enter bot api";  // Replace with your Bot API
const char* CHAT_ID = "-enter supergroup chat id";                    // Replace with your Chat ID

void setup() {
  Serial.begin(115200);
  
  // Initialize sensor pins
  pinMode(PIR_PIN, INPUT);
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(GAS_SENSOR, INPUT);

  // Connect to Wi-Fi
  connectToWiFi();
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);
  int flameDetected = digitalRead(FLAME_SENSOR);
  int gasDetected = digitalRead(GAS_SENSOR);

  // PIR Motion Detection
  if (motionDetected == HIGH) {
    Serial.println("Motion detected!");
    sendTelegramAlert("⚠️ Motion detected in your house!");
  } else {
    Serial.println("No motion detected.");
  }

  // Flame Detection
  if (flameDetected == LOW) {  // Some sensors output LOW when detecting flame
    Serial.println("🔥 Flame Detected!");
    sendTelegramAlert("🔥 Fire Alert! Flame detected in your house!");
  } else {
    Serial.println("No flame detected.");
  }

  // Gas Detection
  if (gasDetected == LOW) {  // Some sensors output LOW when detecting gas
    Serial.println("⚠️ Gas Leak Detected!");
    sendTelegramAlert("⚠️ Gas Leak Alert! Gas detected in your house!");
  } else {
    Serial.println("No gas detected.");
  }

  delay(0.1);  // Check sensors every 1 second
}

// Function to connect to Wi-Fi
void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWi-Fi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// Function to send alerts to Telegram
void sendTelegramAlert(String message) {
  WiFiClientSecure client;
  client.setInsecure();  // Bypass SSL certificate verification

  const char* host = "api.telegram.org";
  const int httpsPort = 443;

  if (!client.connect(host, httpsPort)) {
    Serial.println("⚠️ Connection to Telegram server failed");
    return;
  }

  // Prepare the request URL
  String url = "/bot" + String(TELEGRAM_BOT_API) + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + message;

  // Send GET request to Telegram API
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Wait for response
 /* while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("✅ Telegram Alert Sent");
      break;
    }
  }

  // Read and print the response
  String response = client.readString();
  Serial.println("Response:");
  Serial.println(response);*/
}
