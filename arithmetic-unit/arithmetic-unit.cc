

#include <iostream>

#include "arithmetic-unit.h"

void ArithmeticUnit::executeInstruction(std::shared_ptr<Instruction>& instruction) {
  instruction->execute();
  incrementProgramCounter();
}

void ArithmeticUnit::executeInstructions(ProgramMemory& programMemory) {
  while (programCounter_ < programMemory.getNumberOfInstructions()) {
    std::shared_ptr<Instruction> instruction = programMemory.accessInstruction(programCounter_);
    executeInstruction(instruction);
  }
}
