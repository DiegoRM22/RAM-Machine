

#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"
#include "../data-memory/data-memory.h"

// Class for instruction jump
class JumpInstruction : public Instruction {
 public:
  JumpInstruction() = default;
  JumpInstruction(const PairLabelLine& label) : label_(label) {}
  void execute() override { std::cout << "Jumping to " << label_.getLabel() << " is greater than zero" << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
    std::cout << "Jumping to " << label_.getLabel() << std::endl;
    programCounter = label_.getLine();
  }

 private:
  PairLabelLine label_;
};

#endif