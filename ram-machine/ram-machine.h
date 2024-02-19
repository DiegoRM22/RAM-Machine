
// Class RAM machine, this class loads the program and executes it sequentially.
// Always following the SOLID principles.

#ifndef RAM_MACHINE_H
#define RAM_MACHINE_H

#include <iostream>
#include <fstream>

#include "../input-unit/input-unit.h"
#include "../output-unit/output-unit.h"
#include "../program-memory/program-memory.h"
#include "../instruction/instruction.h"
#include "../data-memory/data-memory.h"
#include "../arithmetic-unit/arithmetic-unit.h"

class RAMMachine {
 public:
  // Constructor
  RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName);
  // Load the program from a file
  void loadProgram(const std::string &filename);

  

 private:
  InputUnit inputUnit_;
  OutputUnit outputUnit_;
  ProgramMemory programMemory_;
  DataMemory dataMemory_;
  ArithmeticUnit arithmeticUnit_;
};

#endif