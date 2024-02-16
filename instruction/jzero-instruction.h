

#ifndef JZERO_H
#define JZERO_H

#include "instruction.h"

// Class for instruction jzero
class JzeroInstruction : public Instruction {
 public:
  JzeroInstruction() = default;
  JzeroInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Jumping to " << operand_ << " if R0 is zero" << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif