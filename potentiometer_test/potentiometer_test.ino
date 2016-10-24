int potPin = 14; 
int val = 0;       
int raw = 0;
const int channel = 1


void setup() {
}

void loop() {
  raw = analogRead(potPin);    // read the value from the sensor
  val = map(raw, 0, 1023, 0, 127);
  usbMIDI.sendControlChange(7, val, 1);
  delay(100);                  // stop the program for some time
}
 
