

#include "read-instruction.h"

/**
 * @brief Executes the read instruction.
 * @param dataMemory The data memory of the machine.
 * @param programCounter The program counter of the machine.
 * @param outputUnit The output unit of the machine.
 * @param inputUnit The input unit of the machine.
 * @return void
*/
void ReadInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Reading " << operand_ << std::endl;
  // Check the type of the operand.
  if (operandType_ == "inmediate" || operand_ == 0) {
    // Error: operand_ is not a register, it is a value or is R0.
    std::cout << operand_ << " [" <<  position_ << std::endl;
    std::cout << "Error en la línea: " << programCounter << " Read instruction does not handle operations with R0 register." 
              << std::endl;
    outputUnit.writeToFile();
    exit(1);
  }
  else if (operandType_ == "direct") {
    dataMemory.setRegister(operand_, inputUnit.getValue(), position_);
  } else if (operandType_ == "indirect") {
    int address = dataMemory.getRegister(operand_);
    dataMemory.setRegister(address, inputUnit.getValue(), position_);
  }
  ++programCounter;
}