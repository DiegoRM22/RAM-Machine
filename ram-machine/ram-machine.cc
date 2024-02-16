
#include "ram-machine.h"

// Constructor
RAMMachine::RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName) {

  ProgramMemory program(ramProgramFileName);
  programMemory_ = program;
  programMemory_.printProgram();
  programMemory_.printLabels();
  programMemory_.printInstructions();
  programMemory_.checkTypeInstruction("store 1");
  programMemory_.accessInstruction(0)->execute();
  programMemory_.checkTypeInstruction("load 1");
  programMemory_.accessInstruction(1)->execute();


}