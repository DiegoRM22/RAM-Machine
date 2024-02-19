

#ifndef MUL_H
#define MUL_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction mul
class MulInstruction : public Instruction {
 public:
  MulInstruction() = default;
  MulInstruction(int operand, std::string operandType, int position = 0) : operand_(operand),
  operandType_(operandType), position_(position) {}
  void execute() override { std::cout << "Multiplying R0 by " << operand_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;

 private:
  int operand_;
  std::string operandType_;
  int position_;
};

#endif