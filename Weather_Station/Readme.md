# Weather Station with Real-Time Display
---
## Description
The Weather Station project uses a DHT22 sensor to measure temperature and humidity and displays the real-time data on an OLED screen. This project is useful for monitoring environmental conditions in a compact and user-friendly manner.

## Components Used
- **ESP32**: Microcontroller to gather sensor data and manage the display.
- **DHT11/22 Sensor**: To measure temperature and humidity.
- **OLED Display (128x64)**: To display real-time weather data.
- **Jumper Wires**: For connections.

## Pin Connections
| Component       | ESP32 Pin |
|-----------------|-----------|
| DHT11/22 Sensor    | P15        |
| OLED SDA        | P21       |
| OLED SCL        | P22       |

## Steps to Implement
1. Connect the DHT22 sensor and OLED display to the ESP32 as per the pin connections.
2. Install the necessary libraries:
   - Adafruit Unified Sensor Library
   - DHT Sensor Library
   - Adafruit SSD1306 Library
3. Upload the provided code to the ESP32.
4. Test the system by exposing the sensor to different conditions.

## Image 
![Weather Station Setup](image2.jpg)

## Testing and Calibration
- **Testing**:
   - Place the sensor in various environments to ensure accurate readings.
- **Calibration**:
   - Adjust the display update interval if necessary.

## Output
The OLED display shows the following data in real-time:
- Temperature (in Celsius or Fahrenheit)
- Humidity (in percentage)

---
This project combines sensor data collection and display functionality, making it a practical and educational endeavor!

