#include <SPI.h>

const int csPinFGen = 2;
const int csPinDPot1 = 3;
const int csPinDPot2 = 4;
const int csPinDPot3 = 5;
const int csPinDPot4 = 6;
const int enPinAmp = 10;

void setup() {
  // Initialize the serial port to output debug info.
  Serial.begin( 9600);

  // Initialize the SPI port since it'll be used all over the place.
  SPI.begin();

  // Setup the various functional groups.
  FunctionGenerator_Setup( csPinFGen);
}

void loop() {
  // Do nothing for now.
}
