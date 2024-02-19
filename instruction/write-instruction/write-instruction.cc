

#include "write-instruction.h"

void WriteInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operand_ == 0 && operandType_ != "inmediate") {
    // Error: operand_ is not a register, it is a value or is R0.
    std::cout << "Error: Write instruction does not handle operations with R0 register." << std::endl;
    exit(1);
  }
  if (operandType_ == "inmediate") {
    outputUnit.write(operand_);
  } else if (operandType_ == "direct") {
    outputUnit.write(dataMemory.getRegister(operand_));
  } else if (operandType_ == "indirect") {
    outputUnit.write(dataMemory.getRegister(dataMemory.getRegister(operand_)));
  }
  ++programCounter;
}