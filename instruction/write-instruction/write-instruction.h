

#ifndef WRITE_H
#define WRITE_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction write
class WriteInstruction : public Instruction {
 public:
  WriteInstruction() = default;
  WriteInstruction(int operand, std::string operandType, int position = 0) : operand_(operand),
  operandType_(operandType), position_(position) {}
  void execute() override { std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;
 private:
  int operand_;
  std::string operandType_;
  int position_;
};

#endif