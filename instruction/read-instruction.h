
#include "instruction.h"

// Class for instruction read
class ReadInstruction : public Instruction {
 public:
  ReadInstruction() = default;
  ReadInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Reading from inout tape, writing into " << operand_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};