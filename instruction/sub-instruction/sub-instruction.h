

#ifndef SUB_H
#define SUB_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction sub
class SubInstruction : public Instruction {
 public:
  SubInstruction() = default;
  SubInstruction(int operand, std::string operandType, int position = 0) : operand_(operand),
  operandType_(operandType), position_(position) {}
  void execute() override { std::cout << "Subtracting " << operand_ << " from R0" << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;

 private:
  int operand_;
  std::string operandType_;
  int position_;
};

#endif