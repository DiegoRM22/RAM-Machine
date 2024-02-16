

#ifndef SUB_H
#define SUB_H

#include "instruction.h"

// Class for instruction sub
class SubInstruction : public Instruction {
 public:
  SubInstruction() = default;
  SubInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Subtracting " << operand_ << " from R0" << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif