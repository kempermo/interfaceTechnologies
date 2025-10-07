void setup()
{
  // open the serial port with a baudrate of 9600
  Serial.begin(9600);
}
 
void loop()
{
  // reading of pins
  int firstValue = analogRead(A0);
  int secondValue = analogRead(A1);
  
  // writing of a single line to serial "100,200"
  Serial.print(firstValue);
  Serial.print(',');
  Serial.print(secondValue);
  Serial.println(); // <- finish of line
}