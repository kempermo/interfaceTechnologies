#include <Arduino.h>
//#include <SPI.h>
#include <TFT_eSPI.h>  // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke library

int angle = 90;

void setup() {
  Serial.begin(9600);

  pinMode(8,OUTPUT);
  
  tft.init();               // Initialize display
  
  tft.setRotation(0);       // Adjust if needed (0–3)

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);   // Middle center alignment

  tft.setTextSize(2);       // Adjust size as needed

  // Draw centered text
  tft.drawString("Hello World", 120, 120); // Center of 240x240
  
  // Draw a box
  tft.drawRect(100, 100, 30, 30, 0xffffff);

  // Draw a round box
  tft.fillRoundRect(100, 150, 40, 30, 15, 0xffffff);
}

void loop() {
  // Nothing needed here
  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  if(angle < 360){
    angle++;
  }

  // Draw Arc
  tft.drawArc(tft.width()/2, tft.height()/2, 100, 90, 0, angle, 0xffffff, 0xff00ff, 1);
}