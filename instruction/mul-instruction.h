

#ifndef MUL_H
#define MUL_H

#include "instruction.h"

// Class for instruction mul
class MulInstruction : public Instruction {
 public:
  MulInstruction() = default;
  MulInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Multiplying R0 by " << operand_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif