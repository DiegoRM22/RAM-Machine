

#ifndef HALT_H
#define HALT_H

#include "instruction.h"
#include "../data-memory/data-memory.h"

// Class for instruction halt
class HaltInstruction : public Instruction {
 public:
  HaltInstruction() = default;
  void execute() override { std::cout << "Halting" << std::endl; }
  void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) override {
    std::cout << "Halting" << std::endl;
    outputUnit.writeToFile();
    exit(0);
  }

};

#endif