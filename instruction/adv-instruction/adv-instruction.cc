

#include "adv-instruction.h"


/**
 * @brief Executes the adv instruction.
 * @param dataMemory The data memory of the machine.
 * @param programCounter The program counter of the machine.
 * @param outputUnit The output unit of the machine.
 * @param inputUnit The input unit of the machine.
 * @return void
*/
void AdvInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Advancing " << operand_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate") {
    std::cout << "Adv instruction does not support inmediate operand type." << std::endl;
    exit(1);
  } else if (operandType_ == "direct") {
    // obtener el tamaño del vector
    int size = dataMemory.getVectorSize(operand_);
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += dataMemory.getRegister(operand_, i);
    }
    dataMemory.setRegister(kAccumulatorDirection, sum);
    std::cout << "Suma de " << operand_ << " = " << sum  << "Cuyo tamaño de vector es: " << size << std::endl;
  } else if (operandType_ == "indirect") {
    // Obtenemos el registro que contiene la dirección del vector
    int vectorAddress = dataMemory.getRegister(operand_);
    // Obtenemos el tamaño del vector
    int size = dataMemory.getVectorSize(vectorAddress);
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += dataMemory.getRegister(vectorAddress, i);
    }
    dataMemory.setRegister(kAccumulatorDirection, sum);
  }
  ++programCounter;
}