

#ifndef HALT_H
#define HALT_H

#include "instruction.h"

// Class for instruction halt
class HaltInstruction : public Instruction {
 public:
  HaltInstruction() = default;
  void execute() override { std::cout << "Halting" << std::endl; }
};

#endif