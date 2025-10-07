import processing.serial.*;

Serial myRfidReader;

String currentID = "";

void setup()
{
  size(500,500);
  //println(Serial.list());
  myRfidReader = new Serial(this, "/dev/tty.usbserial-AH06VX19", 9600);
}

void draw()
{
  if (currentID.equals("0109A2CD0067")) {
    background(255,0,0);
  } else if (currentID.equals("0109A2BD6D7A")) {
    background(255,255,0);
  } else {
    background(0,0,0);
  }
}

void serialEvent(Serial myPort)
{
  // check if data is available
  if (myPort.available() == 0) {
    return;
  }

  // read a line as a string
  String str = myPort.readStringUntil('\n');
  if (str == null) {
    return;
  }

  // remove leading and trailing whitespace
  str = trim(str);
  println(str);

  currentID = str;
}
