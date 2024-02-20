
#include "ram-machine.h"

/**
 * @brief Constructor of the RAMMachine class.
 * @param ramProgramFileName The name of the file that contains the RAM program.
 * @param inputFileName The name of the file that contains the input for the RAM program.
 * @param outputFileName The name of the file that will contain the output of the RAM program.
 * @return void
*/
RAMMachine::RAMMachine(std::string ramProgramFileName, std::string inputFileName, std::string outputFileName) {

  ProgramMemory program(ramProgramFileName);
  programMemory_ = program;
  // programMemory_.printProgram();
  //programMemory_.printLabels();
  
  inputUnit_.setMemory(inputFileName);
  outputUnit_.setOutputFileName(outputFileName);
  
  //arithmeticUnit_.executeInstructions(programMemory_, dataMemory_);
}


/**
 * @brief Destructor of the RAMMachine class.
 * @return
 * @return void
*/
void RAMMachine::runProgram(const std::string &filename, const int debuggOption) {
  while (arithmeticUnit_.programCounter_ < programMemory_.getNumberOfInstructions()) {
    std::shared_ptr<Instruction> instruction = programMemory_.accessInstruction(arithmeticUnit_.programCounter_);
    arithmeticUnit_.executeInstruction(instruction, dataMemory_, arithmeticUnit_.programCounter_, outputUnit_, inputUnit_);
    if (debuggOption == 2) {
      std::cout << "Instrucción ejecutada: " << programMemory_.getInstructionsString()[arithmeticUnit_.programCounter_ - 1] << std::endl;
      std::cout << " Memoria de datos:" << std::endl;
      std::cout << "-------------------" << std::endl;
      dataMemory_.printRegisters();
      std::cout << "-------------------" << std::endl;
      std::cout << "Cinta de entrada y posición actual: " << std::endl;
      inputUnit_.printMemory();
      std::cout << "Cinta de salida: " << std::endl;
      outputUnit_.printMemory();
    }
    arithmeticUnit_.numberOfInstructions_++;
    if (debuggOption == 1 || debuggOption == 2) {
      std::cout << "Número de instrucciones ejecutadas: " << arithmeticUnit_.numberOfInstructions_ << std::endl;
    }
  }
  
  outputUnit_.writeToFile();
}