

#ifndef JGTZ_H
#define JGTZ_H

#include "instruction.h"
#include "../data-memory/data-memory.h"
#include "../pair-label-line.h"

/**
 * @brief The JgtzInstruction class represents the JGTZ instruction of the machine.
*/
class JgtzInstruction : public Instruction {
 public:
  JgtzInstruction() = default;
  JgtzInstruction(const PairLabelLine& label) : label_(label) {}
  void execute() override { std::cout << "Jumping to " << label_.getLabel() << " is greater than zero" << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) {
    if (dataMemory.getRegister(0) > 0) {
      //std::cout << "Jumping to " << label_.getLabel() << " because R0 value is greater than zero" << std::endl;
      programCounter = label_.getLine();
    } else {
      //std::cout << "Not jumping to " << label_.getLabel() << " because R0 value is not greater than zero" << std::endl;
      programCounter++;
    }
  }
 private:
  PairLabelLine label_;
};

#endif