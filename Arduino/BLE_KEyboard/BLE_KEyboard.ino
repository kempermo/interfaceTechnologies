//Include Libraries
#include <BleKeyboard.h>

//Define Inputs for knob with display
#define ENCODER_A 19  //Encoder A 
#define ENCODER_B 18  //Encoder B 

//Used for encoders
#define ENCODER_MAX_VALUE 300   //Max Value
#define ENCODER_MIN_VALUE -300  //Min Value
int encoderIncrement = 1;
int oldEncoderReading = 0;
int encoderValue = 0;
int currEncoderReading = 0;
int oldEncoderValue = 0;

BleKeyboard bleKeyboard("keyboard", "hfg", 100);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  //Enable Encoder Pins
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
}

void loop() {
  encoderValue = readEncoder(ENCODER_A, ENCODER_B);
  if (encoderValue < oldEncoderValue) {
    Serial.println("UP");
    bleKeyboard.write('u');
    delay(10);
  }
  if (encoderValue > oldEncoderValue) {
    Serial.println("DOWN");
    bleKeyboard.write('d');
    delay(10);
  }

  oldEncoderValue = encoderValue;
}
