

#ifndef JZERO_H
#define JZERO_H

#include "instruction.h"
#include "../data-memory/data-memory.h"

// Class for instruction jzero
class JzeroInstruction : public Instruction {
 public:
  JzeroInstruction() = default;
  JzeroInstruction(const PairLabelLine& label) : label_(label) {}
  void execute() override { std::cout << "Jumping to " << label_.getLabel() << " is EQ TO zero" << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
    if (dataMemory.getRegister(0) == 0) {
      std::cout << "Jumping to " << label_.getLabel() << " because R0 value is EQ to zero" << std::endl;
      programCounter = label_.getLine();
    } else {
      std::cout << "Not jumping to " << label_.getLabel() << " because R0 value is not EQ to zero" << std::endl;
      programCounter++;
    }
  }
 private:
  PairLabelLine label_;
};

#endif