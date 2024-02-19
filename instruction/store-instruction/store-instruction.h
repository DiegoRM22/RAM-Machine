

#ifndef STORE_H
#define STORE_H

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction store
class StoreInstruction : public Instruction {
 public:
  StoreInstruction() = default;
  StoreInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Storing R0 into " << operand_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;

 private:
  int operand_;
  std::string operandType_;
};

#endif