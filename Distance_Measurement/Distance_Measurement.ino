#include <Ultrasonic.h>

#define TRIG_PIN 19
#define ECHO_PIN 18

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
    Serial.begin(115200);
}

void loop() {
    long distance = ultrasonic.read(CM);
    // To chabge cm to inch, replace 'CM' to 'INC' 
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500); // Wait before next reading
}