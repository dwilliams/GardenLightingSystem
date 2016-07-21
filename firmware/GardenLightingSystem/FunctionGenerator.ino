// Put the functions for the function generator here.

#include <SPI.h>
#include <SparkFun_MiniGen.h>

MiniGen FunctionGenerator_fgen;

void FunctionGenerator_Setup() {
  Serial.println( "Setting up function generator");
  
  FunctionGenerator_fgen = MiniGen( 2); // Using D2 for the chip select

  // Setup the function generator for 400 Hz
  FunctionGenerator_fgen.reset();

  // NOTE: There's a bug that causes the command register to have the first bit set to '1' when
  //          said bit should be 0.
  //FunctionGenerator_fgen.setMode( MiniGen::SINE);
  
  uint16_t freqRegVal = FunctionGenerator_fgen.freqCalc( 400);
  //FunctionGenerator_fgen.adjustFreq( MiniGen::FREQ0, MiniGen::FULL, freqRegVal);
  //FunctionGenerator_fgen.adjustFreq( MiniGen::FREQ1, MiniGen::FULL, freqRegVal);
  FunctionGenerator_fgen.adjustFreq( MiniGen::FREQ0, freqRegVal);
  FunctionGenerator_fgen.adjustFreq( MiniGen::FREQ1, freqRegVal);
  
  FunctionGenerator_fgen.adjustPhaseShift( MiniGen::PHASE0, 0x0000);
  FunctionGenerator_fgen.adjustPhaseShift( MiniGen::PHASE1, 0x0000);
  
  //SPIWrite(0x0100);
  //SPIWrite(0x0000);
  
  //FunctionGenerator_fgen.selectFreqReg( MiniGen::FREQ0);
  
  Serial.print( "freqRegVal: ");
  Serial.print( freqRegVal, HEX);
  Serial.println( "");
}

