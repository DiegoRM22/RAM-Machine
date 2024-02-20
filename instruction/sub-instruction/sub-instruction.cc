

#include "sub-instruction.h"

/**
 * @brief Executes the sub instruction.
 * @param dataMemory The data memory of the machine.
 * @param programCounter The program counter of the machine.
 * @param outputUnit The output unit of the machine.
 * @param inputUnit The input unit of the machine.
 * @return void
*/
void SubInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Substracting... " << operand_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) - operand_);
  } else if (operandType_ == "direct") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) -
    dataMemory.getRegister(operand_, position_));
  } else if (operandType_ == "indirect") {
    dataMemory.setRegister(kAccumulatorDirection, dataMemory.getRegister(kAccumulatorDirection) -
    dataMemory.getRegister(dataMemory.getRegister(operand_, position_)));
  }
  ++programCounter;
}