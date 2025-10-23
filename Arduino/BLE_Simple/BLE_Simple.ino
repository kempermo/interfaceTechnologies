#include <BleKeyboard.h>  //Import the BLE-Keyboard-Library https://github.com/T-vK/ESP32-BLE-Keyboard

BleKeyboard bleKeyboard("keyboard", "hfg", 100);  //Create an instance of the library – you are free to choose a name

void setup() {
  Serial.begin(115200);  //Start the serial connection
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();  //Start the BLE keyboard
}

void loop() {
  Serial.println("UP");
  bleKeyboard.write('u'); //Send a "u" as a keystroke through bluetooth

  delay(2000); //Wait 2 Seconds 

  Serial.println("DOWN");
  bleKeyboard.write('d'); //Send a "d" as a keystroke through bluetooth

  delay(5000); //Wait 5 seconds
}
