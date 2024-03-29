
#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../pair-label-line.h"
#include "../instruction/instruction.h"

class ProgramMemory {
 public:
  ProgramMemory() = default;
  // Copy constructor
  ProgramMemory(const ProgramMemory& programMemory) : program_(programMemory.program_) {}
  ProgramMemory(std::string ramProgramFileName);
  std::shared_ptr<Instruction> accessInstruction(const int programCounter);

  int getLabelLine(const std::string &label);
  int getNumberOfInstructions() const { return instructions.size(); }
  std::vector<std::string> getInstructionsString() const { return instructions_; }

  void findLabels(const std::string& program);
  

  void checkTypeInstruction(const std::string& instruction, const int instructionOPerand, const std::string& operandType,
                            const PairLabelLine& pairLabelLine = PairLabelLine());

  void printProgram() const { std::cout << program_; }
  void printLabels() const;
  void printInstructions() const;
  void executeInstructions();

  bool isALabel(const std::string& label) const;
 private:
  std::string program_;
  std::vector<PairLabelLine> labels_;
  std::vector<std::string> instructions_;
  std::vector<std::shared_ptr<Instruction>> instructions;
  
};

#endif