#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Ultrasonic.h>

// OLED Display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Ultrasonic Sensor Pins
#define TRIG_PIN 19 
#define ECHO_PIN 18
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Default I2C address 0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println(F("Distance"));
  display.display();
  delay(2000);
}

void loop() {
  long distance = ultrasonic.read(CM);  // Use 'read(INC)' to measure distance in inch
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display on OLED
  display.clearDisplay();
  display.setCursor(20, 10);
  display.setTextSize(1);
  display.print("Distance:");
  display.setCursor(30, 35);
  display.setTextSize(1);
  display.print(distance);
  display.print(" cm");
  display.display();

  delay(1000);
}
