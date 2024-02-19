
#ifndef ARITHMETIC_UNIT_H
#define ARITHMETIC_UNIT_H

#include "../instruction/instruction.h"
#include "../program-memory/program-memory.h"

class ArithmeticUnit {
 public:
  ArithmeticUnit() : programCounter_(0) {}
  void incrementProgramCounter() { programCounter_++; }
  void jump(int address) { programCounter_ = address; }
  int getProgramCounter() const { return programCounter_; }
  void executeInstructions(ProgramMemory& programMemory, DataMemory& dataMemory);
  void executeInstruction(std::shared_ptr<Instruction>& instruction, DataMemory& dataMemory,
                          int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit);

  friend class RAMMachine;
  
 private:
  int programCounter_;

};

#endif