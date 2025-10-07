import processing.serial.*;
Serial myPort;

int firstValue, secondValue;

void setup()
{
  size(500, 500);

  // print all available ports
  println(Serial.list());

  // open specific serial port
  myPort = new Serial(this, "/dev/cu.usbmodem12131", 9600);
}

void draw()
{
  // draw ellipse
  background(0);
  fill(255);
  ellipse(width/2, height/2, firstValue, secondValue);
}

void serialEvent(Serial myPort)
{
  // check if data is available
  if (myPort.available() == 0)
  {
    return;
  }

  // read a line as a string
  String str = myPort.readStringUntil('\n');
  if (str == null)
  { 
    return;
  }

  // remove leading and trailing whitespace
  str = trim(str);

  // split string
  String vals[] = split(str, ",");
  if (vals.length != 2) {
    return;
  }

  // convert values
  firstValue = int(vals[0]);
  secondValue = int(vals[1]);
  println(firstValue, secondValue);
}
