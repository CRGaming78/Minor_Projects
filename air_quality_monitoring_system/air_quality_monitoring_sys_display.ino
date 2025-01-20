#include <Wire.h>
#include <Adafruit_SSD1306.h>

// OLED Display Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// OLED SDA Pin: 21, OLED SCL Pin: 22 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define MQ135_PIN 12 // MQ-135 connected to Analog Pin P12

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Halt
  }
  display.clearDisplay();
  display.display();

  pinMode(MQ135_PIN, INPUT);
  displayText("Air Quality", "Monitoring", "System");
  delay(2000);
}

void loop() {
  int analogValue = analogRead(MQ135_PIN);
  String airQuality = getAirQualityLevel(analogValue);

  displayData(analogValue, airQuality);
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Air Quality: ");
  Serial.println(airQuality);
  delay(1500);
}

String getAirQualityLevel(int value) {
  if (value < 1000) return "Good";
  else if (value < 1500) return "Moderate";
  else if (value < 2250) return "Poor";
  else return "Hazardous";
}

void displayText(String line1, String line2, String line3) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(line1);
  display.println(line2);
  display.println(line3);
  display.display();
}

void displayData(int value, String quality) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("MQ-135 Sensor");
  display.print("Value: ");
  display.println(value);
  display.print("Quality: ");
  display.println(quality);
  display.display();
}
