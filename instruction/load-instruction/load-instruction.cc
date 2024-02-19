

#include "load-instruction.h"

void LoadInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Loading " << operand_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate") {
    dataMemory.setRegister(kAccumulatorDirection, operand_, position_);
  } else if (operandType_ == "direct") {
    std::cout << "Loading from " << operand_ << "[" << position_ << "]" << " to " << kAccumulatorDirection << std::endl;
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(operand_, position_));
  } else if (operandType_ == "indirect") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(dataMemory.getRegister(operand_, position_)));
  }
  ++programCounter;
}