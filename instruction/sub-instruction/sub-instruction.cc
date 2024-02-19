

#include "sub-instruction.h"

void SubInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  std::cout << "Substracting... " << operand_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) - operand_);
  } else if (operandType_ == "direct") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) - dataMemory.getRegister(operand_));
  } else if (operandType_ == "indirect") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) -
    dataMemory.getRegister(dataMemory.getRegister(operand_)));
  }
  ++programCounter;
}