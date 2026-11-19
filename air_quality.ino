#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi Details
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// MQ-135 Sensor
#define MQ135_PIN A0

// KiwisIoT Initialization
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("IoT Air Quality Monitoring");

  kiwisiot.begin();

  Serial.println("MQ-135 Sensor Initialized");
  Serial.println("Connecting to KiwisIoT...");
}

void loop() {

  // Maintain platform connection
  kiwisiot.run();

  if (millis() - previousMillis >= interval) {

    previousMillis = millis();

    // Read sensor value
    int airValue = analogRead(MQ135_PIN);

    // Display sensor value
    Serial.println("------------------------");

    Serial.print("Air Quality Value: ");
    Serial.println(airValue);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(a