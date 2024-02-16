

// Eigen class for instruction

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>


class Instruction {
 public:
  virtual void execute() = 0;
  virtual ~Instruction() = default;
};

#endif