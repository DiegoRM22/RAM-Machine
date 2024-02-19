

#include "store-instruction.h"

void StoreInstruction::execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  //std::cout << "Storing... " << operand_ << std::endl;
  // Check the type of the operand.
  const int kAccumulatorDirection = 0;
  if (operandType_ == "inmediate") {
    // Error: STORE doesnt handle inmediate values, stop program execution
    // Falta volcar la cola de salida en un archivo.
    std::cout << "Error en la linea: " << programCounter << " STORE doesnt handle inmediate values, stop program execution"
              << std::endl;
    outputUnit.writeToFile();
    exit(1);
  } else if (operandType_ == "direct") {
    dataMemory.setRegister(operand_, dataMemory.getRegister(kAccumulatorDirection));
  } else if (operandType_ == "indirect") {
    dataMemory.setRegister(dataMemory.getRegister(operand_), dataMemory.getRegister(kAccumulatorDirection));
  }
  ++programCounter;
}