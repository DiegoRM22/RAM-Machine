

#include "write-instruction.h"

void WriteInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate" || operand_ == 0) {
    // Error: operand_ is not a register, it is a value or is R0.
    std::cout << "Error: operand_ is not a register, it is a value or is R0." << std::endl;
    exit(1);
  } else if (operandType_ == "direct") {
    outputUnit.write(dataMemory.getRegister(operand_));
  } else if (operandType_ == "indirect") {
    outputUnit.write(dataMemory.getRegister(dataMemory.getRegister(operand_)));
  }
  ++programCounter;
}