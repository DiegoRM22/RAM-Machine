

#ifndef DIV_H
#define DIV_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction div
class DivInstruction : public Instruction {
 public:
  DivInstruction() = default;
  DivInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Dividing R0 by " << operand_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;
 private:
  int operand_;
  std::string operandType_;
};

#endif