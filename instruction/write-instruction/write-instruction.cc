

#include "write-instruction.h"

/**
 * @brief Executes the write instruction.
 * @param dataMemory The data memory of the machine.
 * @param programCounter The program counter of the machine.
 * @param outputUnit The output unit of the machine.
 * @param inputUnit The input unit of the machine.
 * @return void
*/
void WriteInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operand_ == 0 && operandType_ != "inmediate") {
    // Error: operand_ is not a register, it is a value or is R0.
    std::cout << "Error en la línea: " << programCounter << " Write instruction does not handle operations with R0 register."
              << std::endl;
    outputUnit.writeToFile();
    exit(1);
  }
  if (operandType_ == "inmediate") {
    outputUnit.write(operand_);
  } else if (operandType_ == "direct") {
    outputUnit.write(dataMemory.getRegister(operand_, position_));
  } else if (operandType_ == "indirect") {
    outputUnit.write(dataMemory.getRegister(dataMemory.getRegister(operand_, position_)));
  }
  ++programCounter;
}