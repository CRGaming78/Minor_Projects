#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define MQ135_ANALOG_PIN 12

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int mq135_analog=analogRead(MQ135_ANALOG_PIN);
  String airQuality = getAirQualityDescription(mq135_analog);
  Serial.print("MQ-135 Analog Value: ");
  Serial.println(mq135_analog);
  Serial.print("Air Quality: ");
  Serial.println(airQuality);
  delay(1000);
}

String getAirQualityDescription(int value) {
  if (value < 1000) {
    return "Good";  
  } else if (value < 1750) {
    return "Moderate";     
  } else if (value < 2500) {
    return "Poor";
  } else {
    return "Very Poor";
  }
}
