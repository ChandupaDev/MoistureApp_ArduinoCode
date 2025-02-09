#include <WiFi.h>

// Wi-Fi credentials
const char* ssid = "Thunder";
const char* password = "Thunder1234";

// Pins and Constants
#define SOIL_SENSOR_PIN A0
#define DRY_VALUE 4095
#define WET_VALUE 3400
#define RELAY_PIN 17

WiFiServer server(80);

int sensorValue = 0;
int moisturePercentage = 0;
bool pumpState = false; // Tracks pump ON/OFF state

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF by default

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); 
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  // Check for a client connection
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client Connected");
    String request = client.readStringUntil('\r'); // Read the HTTP request
    Serial.println(request);

    // Parse the command from the request
    if (request.indexOf("GET /?command=turn_on") >= 0) {
      pumpState = true;
      digitalWrite(RELAY_PIN, LOW); // Turn pump ON
      Serial.println("Pump turned ON");
    } else if (request.indexOf("GET /?command=turn_off") >= 0) {
      pumpState = false;
      digitalWrite(RELAY_PIN, HIGH); // Turn pump OFF
      Serial.println("Pump turned OFF");
    }

    // Read and calculate soil moisture
    sensorValue = analogRead(SOIL_SENSOR_PIN);
    moisturePercentage = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);
    moisturePercentage = constrain(moisturePercentage, 0, 100);

    // Prepare response
    String json = "{";
    json += "\"moisturePercentage\":" + String(moisturePercentage) + ",";
    json += "\"pumpState\":" + String(pumpState);
    json += "}";

    // Send HTTP response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();
    client.println(json);

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}