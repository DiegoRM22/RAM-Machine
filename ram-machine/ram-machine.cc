
#include "ram-machine.h"

// Constructor
RAMMachine::RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName) {

  ProgramMemory program(ramProgramFileName);
  programMemory_ = program;
  // programMemory_.printProgram();
  //programMemory_.printLabels();
  
  inputUnit_.setMemory(inputFileName);
  outputUnit_.setOutputFileName(outputFileName);
  
  //arithmeticUnit_.executeInstructions(programMemory_, dataMemory_);
}

// Load the program from a file
void RAMMachine::runProgram(const std::string &filename, const int debuggOption) {
  while (arithmeticUnit_.programCounter_ < programMemory_.getNumberOfInstructions()) {
    std::shared_ptr<Instruction> instruction = programMemory_.accessInstruction(arithmeticUnit_.programCounter_);
    arithmeticUnit_.executeInstruction(instruction, dataMemory_, arithmeticUnit_.programCounter_, outputUnit_, inputUnit_);
    if (debuggOption == 2) {
      std::cout << "Instrucción ejecutada: " << programMemory_.getInstructionsString()[arithmeticUnit_.programCounter_] << std::endl;
      std::cout << " Memoria de datos:" << std::endl;
      std::cout << "-------------------" << std::endl;
      dataMemory_.printRegisters();
      std::cout << "-------------------" << std::endl;
      std::cout << "Cinta de entrada y posición actual: " << std::endl;
      inputUnit_.printMemory();
      std::cout << "Cinta de salida: " << std::endl;
      outputUnit_.printMemory();
    }
    //std::cout << "Program counter: " << arithmeticUnit_.programCounter_ << std::endl;
    //outputUnit_.printMemory();
    //std::cout << "-------------------" << std::endl;
    arithmeticUnit_.numberOfInstructions_++;
    if (debuggOption == 1 || debuggOption == 2) {
      std::cout << "Número de instrucciones ejecutadas: " << arithmeticUnit_.numberOfInstructions_ << std::endl;
    }
    
  }
  
  outputUnit_.writeToFile();
}