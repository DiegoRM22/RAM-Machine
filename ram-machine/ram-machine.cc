
#include "ram-machine.h"

// Constructor
RAMMachine::RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName) {

  ProgramMemory program(ramProgramFileName);
  programMemory_ = program;
  // programMemory_.printProgram();
  programMemory_.printLabels();
  //programMemory_.printInstructions();
  //programMemory_.checkTypeInstruction("store =1", "inmediate");
  // programMemory_.checkTypeInstruction("load =", 3, "inmediate");
  // PairLabelLine pairLabelLine("lee", 5);
  // programMemory_.checkTypeInstruction("jgtz lee", 0, "inmediate", pairLabelLine);
  // PairLabelLine pairLabelLine2("NO lee", 9);
  // programMemory_.checkTypeInstruction("jzero NO lee", 0, "inmediate", pairLabelLine2);
  // PairLabelLine pairLabelLine3("SALTA SIEMPRE", 20);
  // programMemory_.checkTypeInstruction("jump SALTA SIEMPRE", 0, "inmediate", pairLabelLine3);
  //std::vector<int> inputUnit = {1, 2, 3, 4, 0, 1};
  inputUnit_.setMemory(inputFileName);
  outputUnit_.setOutputFileName(outputFileName);
  // programMemory_.checkTypeInstruction("read 1", 1, "direct");
  // programMemory_.checkTypeInstruction("read 2", 2, "direct");
  // programMemory_.checkTypeInstruction("read 3", 3, "direct");
  // programMemory_.checkTypeInstruction("read 4", 4, "direct");
  // programMemory_.checkTypeInstruction("read 6", 6, "direct");
  // programMemory_.checkTypeInstruction("read 7", 7, "direct");

  // programMemory_.checkTypeInstruction("write 1", 1, "direct");
  // programMemory_.checkTypeInstruction("write 2", 2, "direct");
  // programMemory_.checkTypeInstruction("write 3", 3, "direct");
  // programMemory_.checkTypeInstruction("write 4", 4, "direct");
  // programMemory_.checkTypeInstruction("write 6", 6, "direct");
  // //programMemory_.checkTypeInstruction("halt", 7, "direct");
  // programMemory_.checkTypeInstruction("write 7", 7, "indirect");

  // programMemory_.checkTypeInstruction("jump 1", "inmediate");
  // programMemory_.checkTypeInstruction("jumpz 1", "inmediate");
  // programMemory_.checkTypeInstruction("add 1", "inmediate");
  // programMemory_.checkTypeInstruction("sub 1", "inmediate");
  // programMemory_.checkTypeInstruction("mul 1", "inmediate");
  // programMemory_.checkTypeInstruction("div 1", "inmediate");
  // programMemory_.checkTypeInstruction("write 1", "inmediate");
  // programMemory_.checkTypeInstruction("read 1", "inmediate");
  // programMemory_.checkTypeInstruction("halt", "inmediate");
  // programMemory_.checkTypeInstruction("jgtz 1", "inmediate");
  //programMemory_.executeInstructions();
  //dataMemory_.printRegisters();
  
  while (arithmeticUnit_.programCounter_ < programMemory_.getNumberOfInstructions()) {
    std::shared_ptr<Instruction> instruction = programMemory_.accessInstruction(arithmeticUnit_.programCounter_);
    arithmeticUnit_.executeInstruction(instruction, dataMemory_, arithmeticUnit_.programCounter_, outputUnit_, inputUnit_);
    dataMemory_.printRegisters();
    std::cout << "Program counter: " << arithmeticUnit_.programCounter_ << std::endl;
    outputUnit_.printMemory();
    std::cout << "-------------------" << std::endl;
    outputUnit_.writeToFile();
  }

  //arithmeticUnit_.executeInstructions(programMemory_, dataMemory_);
}