
#ifndef ADV_INSTRUCTION_H
#define ADV_INSTRUCTION_H

#include "../instruction.h"

class AdvInstruction : public Instruction {
 public:
  AdvInstruction() = default;
  AdvInstruction(int operand, std::string operandType, int position = 0) : operand_(operand),
  operandType_(operandType), position_(position) {}
  void execute() override { std::cout << "Adding vector " << operand_ << " to " << operandType_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;
 private:
  int operand_;
  std::string operandType_;
  int position_ = 0;
};

#endif