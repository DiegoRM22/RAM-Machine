

#ifndef WRITE_H
#define WRITE_H

#include "instruction.h"
#include "../data-memory/data-memory.h"

// Class for instruction write
class WriteInstruction : public Instruction {
 public:
  WriteInstruction() = default;
  WriteInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override { std::cout << "Writing " << operand_ << " to " << operandType_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};

#endif