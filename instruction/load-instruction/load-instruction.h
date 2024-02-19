

#include "../instruction.h"
#include "../../data-memory/data-memory.h"

// Class for instruction read
class LoadInstruction : public Instruction {
 public:
  LoadInstruction() = default;
  LoadInstruction(int operand, std::string operandType) : operand_(operand),
  operandType_(operandType) {}
  void execute() override { std::cout << "Loading " << operand_ << " to " << operandType_ << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override;
 private:
  int operand_;
  std::string operandType_;
};