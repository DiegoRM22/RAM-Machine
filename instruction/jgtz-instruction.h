

#ifndef JGTZ_H
#define JGTZ_H

#include "instruction.h"

// Class for instruction jgtz
class JgtzInstruction : public Instruction {
 public:
  JgtzInstruction() = default;
  JgtzInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Jumping to " << operand_ << " if " << operandType_ << " is greater than zero" << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif