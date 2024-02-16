

#ifndef DIV_H
#define DIV_H

#include "instruction.h"

// Class for instruction div
class DivInstruction : public Instruction {
 public:
  DivInstruction() = default;
  DivInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Dividing R0 by " << operand_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif