
#include "ram-machine.h"

// Constructor
RAMMachine::RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName) {

  ProgramMemory program(ramProgramFileName);
  programMemory_ = program;
  programMemory_.printProgram();
  programMemory_.printLabels();
  programMemory_.printInstructions();
  programMemory_.checkTypeInstruction("store 1");
  programMemory_.checkTypeInstruction("load 1");
  programMemory_.checkTypeInstruction("jump 1");
  programMemory_.checkTypeInstruction("jumpz 1");
  programMemory_.checkTypeInstruction("add 1");
  programMemory_.checkTypeInstruction("sub 1");
  programMemory_.checkTypeInstruction("mul 1");
  programMemory_.checkTypeInstruction("div 1");
  programMemory_.checkTypeInstruction("write 1");
  programMemory_.checkTypeInstruction("read 1");
  programMemory_.checkTypeInstruction("halt");
  programMemory_.checkTypeInstruction("jgtz 1");
  programMemory_.executeInstructions();

}