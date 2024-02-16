

#include "instruction.h"

// Class for instruction read
class LoadInstruction : public Instruction {
 public:
  LoadInstruction() = default;
  LoadInstruction(int operand, std::string operandType) : operand_(operand), operandType_(operandType) {}
  void execute() override { std::cout << "Cargando el operando " << operand_ << " En R0. " << " de tipo: " << operandType_ << std::endl; }
 private:
  int operand_;
  std::string operandType_;
};