// Put the functions for the function generator here.

#include <SPI.h>
#include <SparkFun_MiniGen.h>

MiniGen FunctionGenerator_fgen;

void FunctionGenerator_Setup() {
  Serial.println( "Setting up function generator");
  
  FunctionGenerator_fgen = MiniGen( 2); // Using D2 for the chip select

  // Setup the function generator for 400 Hz
  FunctionGenerator_fgen.reset();
  delay( 100);
  FunctionGenerator_fgen.setMode( MiniGen::SINE);
  delay( 100);
  uint32_t freqRegVal = FunctionGenerator_fgen.freqCalc( 400);
  FunctionGenerator_fgen.adjustFreq( MiniGen::FREQ0, MiniGen::FULL, freqRegVal);
  delay( 100);
  FunctionGenerator_fgen.selectFreqReg( MiniGen::FREQ0);
  
  Serial.print( "freqRegVal: ");
  Serial.print( freqRegVal, HEX);
  Serial.println( "");
}

