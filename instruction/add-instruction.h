

#ifndef ADD_H
#define ADD_H

#include "instruction.h"

// Class for instruction add
class AddInstruction : public Instruction {
 public:
  AddInstruction() = default;
  AddInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Adding " << operand_ << " to " << operandType_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif