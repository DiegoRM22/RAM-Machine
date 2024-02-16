

#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"

// Class for instruction jump
class JumpInstruction : public Instruction {
 public:
  JumpInstruction() = default;
  JumpInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Jumping to " << operand_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif