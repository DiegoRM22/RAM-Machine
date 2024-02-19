

#include <iostream>

#include "arithmetic-unit.h"

void ArithmeticUnit::executeInstruction(std::shared_ptr<Instruction>& instruction, DataMemory& dataMemory,
                                        int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
  instruction->execute(dataMemory, programCounter, outputUnit, inputUnit);
}

// void ArithmeticUnit::executeInstructions(ProgramMemory& programMemory, DataMemory& dataMemory) {
//   while (programCounter_ < programMemory.getNumberOfInstructions()) {
//     std::shared_ptr<Instruction> instruction = programMemory.accessInstruction(programCounter_);
//     executeInstruction(instruction, dataMemory);
//   }
// }
