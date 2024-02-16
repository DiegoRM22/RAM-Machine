
#include <algorithm>

#include "program-memory.h"
#include "../instruction/read-instruction.h"
#include "../instruction/load-instruction.h"

#define STORE = "STORE"

ProgramMemory::ProgramMemory(std::string ramProgramFileName) {
  std::string line;
  std::ifstream ramProgramFile(ramProgramFileName);
  int lineCounter = 0;
  while (std::getline(ramProgramFile, line)) {
    // Check if the line is a comment and if is not empty
    if (line[0] != '#' && !line.empty()) {
      // Check if the line is a label -> there's a : in the line
      if (line.find(':') != std::string::npos) {
        // Split the line in two parts: label and instruction
        std::string label = line.substr(0, line.find(':'));
        std::string instruction = line.substr(line.find(':') + 1, line.size());
        // Add the label and the line to the vector
        labels_.push_back(PairLabelLine(label, lineCounter));
        // Eliminar los espacios en blanco del principio solo
        instruction.erase(instruction.begin(), std::find_if(instruction.begin(), instruction.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        instructions_.push_back(instruction);
        // Add the instruction to the program
        program_ += instruction + "\n";
      } else {
        program_ += (ramProgramFile.peek() == ramProgramFile.eof()) ? line : line + "\n";
        // Eliminar los espacios en blanco del principio solo
        line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        instructions_.push_back(line);
      }
      lineCounter++;
    }
  }
  

}

int ProgramMemory::getLabelLine(const std::string &label) {
  for (int i = 0; i < labels_.size(); i++) {
    if (labels_[i].getLabel() == label) {
      return labels_[i].getLine();
    }
  }
  return -1;
}

void ProgramMemory::printInstructions() const{
  std::cout << "Instructions: " << std::endl;
  for (int i = 0; i < instructions_.size(); i++) {
    std::cout << instructions_[i] << std::endl;
  }
}

void ProgramMemory::printLabels() const {
  std::cout << "Labels: " << std::endl;
  for (int i = 0; i < labels_.size(); i++) {
    std::cout << labels_[i].getLabel() << " " << labels_[i].getLine() << std::endl;
  }
}

void ProgramMemory::checkTypeInstruction(const std::string& instruction) {
  // convertimos la instruccion a minusculas
  std::string instructionLower = instruction;
  if (instruction.find("store") != std::string::npos) {
    ReadInstruction readInstruction(1, "inmediate");
    instructions.push_back(std::make_shared<ReadInstruction>(readInstruction));
  } else if (instruction.find("load") != std::string::npos) {
    LoadInstruction loadInstruction(1, "inmediate");
    instructions.push_back(std::make_shared<LoadInstruction>(loadInstruction));
  }
}

std::shared_ptr<Instruction> ProgramMemory::accessInstruction(const int programCounter) {
  if (programCounter < instructions.size()) {
    return instructions[programCounter];
  } else {
    std::cout << "Error: program counter out of bounds" << std::endl;
    return nullptr;
  }
}