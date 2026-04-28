#include <Arduino.h>

// ESP32-C3 Super Mini pin assignments
// A4 = GPIO4, A3 = GPIO3
const int PIN_X   = 4;   // A4 — joystick X axis
const int PIN_Y   = 3;   // A3 — joystick Y axis
const int PIN_BTN = 2;   // GPIO2 — joystick button (active LOW)

const int SEND_INTERVAL_MS = 20;  // ~50 Hz

void setup() {
    Serial.begin(115200);
    analogReadResolution(12);  // 0–4095
    pinMode(PIN_BTN, INPUT_PULLUP);
}

void loop() {
    static unsigned long lastSend = 0;
    unsigned long now = millis();

    if (now - lastSend >= SEND_INTERVAL_MS) {
        lastSend = now;

        int x   = analogRead(PIN_X);
        int y   = analogRead(PIN_Y);
        int btn = !digitalRead(PIN_BTN);  // invert: 1 = pressed

        // Output compact JSON terminated with newline
        Serial.printf("{\"x\":%d,\"y\":%d,\"btn\":%d}\n", x, y, btn);
    }
}
