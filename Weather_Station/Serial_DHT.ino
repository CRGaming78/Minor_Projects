#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// DHT22 configuration
#define DHTPIN 15  // GPIO pin connected to the DHT22 data pin
#define DHTTYPE DHT22 // DHT type (DHT11, DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Test!");

  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Wait before taking the next reading
  delay(2000);
}
