int readEncoder(int _pinA, int _pinB)
{
  int MSB = digitalRead(_pinA);  //MSB = most significant bit
  int LSB = digitalRead(_pinB);  //LSB = least significant bit

  int encoded = (MSB << 1) | LSB;          //converting the 2 pin value to single number
  int sum = (oldEncoderReading << 2) | encoded;  //adding it to the previous encoded value
  //Serial.print("Encoder: ");
  //Serial.println(sum, BIN);
  if (sum == 0b1101) encoderValue--; // || sum == 0b0100 || sum == 0b0010 || sum == 0b1011
  if (sum == 0b1110) encoderValue++; //|| sum == 0b0111 || sum == 0b0001 || sum == 0b1000

  oldEncoderReading = encoded;  //store this value for next time

  return encoderValue;
}