
#ifndef READ_INSTRUCTION_H
#define READ_INSTRUCTION_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction read
class ReadInstruction : public Instruction {
 public:
  ReadInstruction() = default;
  ReadInstruction(int operand, std::string operandType, int position = 0) : operand_(operand),
  operandType_(operandType), position_(position) {}
  void execute() override { std::cout << "Reading from inout tape, writing into " << operand_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;

 private:
  int operand_;
  std::string operandType_;
  int position_;
};

#endif