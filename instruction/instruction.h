

// Eigen class for instruction

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>

#include "../data-memory/data-memory.h"
#include "../output-unit/output-unit.h"
#include "../input-unit/input-unit.h"
#include "../pair-label-line.h"


class Instruction {
 public:
  virtual void execute() = 0;
  virtual void execute(DataMemory& dataMemory, int& programCounter, OutputUnit& outputUnit, InputUnit& inputUnit) = 0;
  virtual ~Instruction() = default;
};

#endif