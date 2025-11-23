#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
#define SOIL_PIN 34
#define RELAY_PIN 13

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32-Invernadero")) {
      Serial.println("MQTT conectado");
    } else {
      delay(500);
    }
  }
}

void setup() {
  Serial.begin(115200);

  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Conectado");

  client.setServer(mqtt_server, 1883);
  reconnect();
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int suelo = analogRead(SOIL_PIN);

  client.publish("invernadero/temperatura", String(t).c_str());
  client.publish("invernadero/humedad", String(h).c_str());
  client.publish("invernadero/suelo", String(suelo).c_str());

  if (suelo < 2500) {
    digitalWrite(RELAY_PIN, HIGH);
    client.publish("invernadero/riego", "ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);
    client.publish("invernadero/riego", "OFF");
  }

  Serial.println("------");
  Serial.print("Temp: "); Serial.println(t);
  Serial.print("Hum:  "); Serial.println(h);
  Serial.print("Suelo:"); Serial.println(suelo);

  delay(2000);
}
