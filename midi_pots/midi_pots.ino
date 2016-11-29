int pot1 = 17; 
int val1 = 0;       
int raw1 = 0;

int pot2 = 16; 
int val2 = 0;       
int raw2 = 0;

int pot3 = 15; 
int val3 = 0;       
int raw3 = 0;
const int channel = 1;


void setup() {
}

void loop() {
  raw1 = analogRead(pot1);    // read the value from the sensors
  raw2 = analogRead(pot2);    
  raw3 = analogRead(pot3); 
     
  val1 = map(raw1, 0, 1023, 0, 127); // map sensors to 7-bit midi values
  val2 = map(raw2, 0, 1023, 0, 127);
  val3 = map(raw3, 0, 1023, 0, 127);
  
  usbMIDI.sendControlChange(1, val1, 1); // send each mapped value as a midi CC
  usbMIDI.sendControlChange(2, val2, 1);
  usbMIDI.sendControlChange(3, val3, 1);

  delay(100);                  // slow your roll
}
 
