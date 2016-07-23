// Put the functions for the function generator here.

#include <SPI.h>

// Configure the normal mode of operation for the config register
const uint16_t configReg = 0x0200;

// Configure the frequency register value for 400 Hz (400.0 / 0.0596).
// Note: Make sure the upper two bits are 0 as they will be used to set the register
const uint32_t freqRegVal = 0x1A37;

void writeData( int csPin, uint16_t data) {
  // Set the chip select pin to low to enable writing to the chip.
  digitalWrite( csPin, LOW);
  
  // Write the data.
  SPI.transfer( (byte) (data>>8));
  SPI.transfer( (byte) data);
  
  // Set the chip select pin to high to disable writing to the chip.
  digitalWrite( csPin, HIGH);
}

void FunctionGenerator_Setup( int csPin) {
  Serial.println( "Setting up function generator");

  // Calculate the register value for 400 Hz.
  uint32_t freqRegVal = 400.0 / 0.0596;

  // Setup the chip select as an output.
  digitalWrite( csPin, HIGH);
  pinMode( csPin, OUTPUT);

  // Begin the SPI transaction with settings that are safe for the AD9837
  SPI.beginTransaction( SPISettings( 10000000, MSBFIRST, SPI_MODE2));

  // Reset the chip using it's internal reset function.
  writeData( csPin, 0x0100);
  writeData( csPin, configReg);

  // Set the Frequency and Phase registers
  writeData( csPin, ( 0x4000 | freqRegVal));  // Set Freq0 to 400 Hz.
  writeData( csPin, ( 0x8000 | freqRegVal));  // Set Freq1 to 400 Hz.
  writeData( csPin, 0xC000);  // Set Phase0 to 0.
  writeData( csPin, 0xE000);  // Set Phase1 to 0.

  // End the SPI transaction so other devices on the bus can be used.
  SPI.endTransaction();
  
  Serial.print( "Done setting up function generator using freqRegVal: ");
  Serial.print( freqRegVal, HEX);
  Serial.println( "");
}

