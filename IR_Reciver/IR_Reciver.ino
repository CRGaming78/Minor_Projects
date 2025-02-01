#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <IRremote.hpp>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define IR_PIN 5  // GPIO pin connected to the OUT pin of TSOP1838, or any other IR sensor (Allways check for the pinout)

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Default I2C address 0x3C, change if 0X3D
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);  // Stay here if display initialization fails
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);  
  display.println(F("IR Receiver Test"));
  display.display();
  delay(2000);
}

void loop() {
  if (IrReceiver.decode()) {
    // Print IR data to Serial Monitor
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);

    // Display the IR code on OLED display
    display.clearDisplay();
    display.setCursor(0, 0); // if you want to keep the first line then set the 2nd/y value to 10
    display.setTextSize(1);
    display.print("IR Code: ");
    display.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    display.display();

    IrReceiver.resume();  // Enable receiving of the next value
  }
}
