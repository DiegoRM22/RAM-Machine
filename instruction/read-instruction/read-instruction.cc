

#include "read-instruction.h"

void ReadInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  std::cout << "Reading " << operand_ << std::endl;
  // Check the type of the operand.
  if (operandType_ == "inmediate" || operand_ == 0) {
    // Error: operand_ is not a register, it is a value or is R0.
    exit(1);
  }
  else if (operandType_ == "direct") {
    dataMemory.setRegister(operand_, inputUnit.getValue());
  } else if (operandType_ == "indirect") {
    int address = dataMemory.getRegister(operand_);
    dataMemory.setRegister(address, inputUnit.getValue());
  }
  ++programCounter;
}