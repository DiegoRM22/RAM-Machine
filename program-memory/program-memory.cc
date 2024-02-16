
#include <algorithm>

#include "program-memory.h"
#include "../instruction/read-instruction.h"
#include "../instruction/load-instruction.h"
#include "../instruction/store-instruction.h"
#include "../instruction/div-instruction.h"
#include "../instruction/mul-instruction.h"
#include "../instruction/add-instruction.h"
#include "../instruction/sub-instruction.h"
#include "../instruction/jump-instruction.h"
#include "../instruction/jzero-instruction.h"
#include "../instruction/jgtz-instruction.h"
#include "../instruction/halt-instruction.h"
#include "../instruction/read-instruction.h"
#include "../instruction/write-instruction.h"


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
    instructions.push_back(std::make_shared<ReadInstruction>(ReadInstruction(1, "inmediate")));
  } else if (instruction.find("load") != std::string::npos) {
    instructions.push_back(std::make_shared<LoadInstruction>(LoadInstruction(1, "inmediate")));
  } else if (instruction.find("store") != std::string::npos) {
    instructions.push_back(std::make_shared<StoreInstruction>(StoreInstruction(1, "inmediate")));
  } else if (instruction.find("div") != std::string::npos) {
    instructions.push_back(std::make_shared<DivInstruction>(DivInstruction(1, "inmediate")));
  } else if (instruction.find("mul") != std::string::npos) {
    instructions.push_back(std::make_shared<MulInstruction>(MulInstruction(1, "inmediate")));
  } else if (instruction.find("add") != std::string::npos) {
    instructions.push_back(std::make_shared<AddInstruction>(AddInstruction(1, "inmediate")));
  } else if (instruction.find("sub") != std::string::npos) {
    instructions.push_back(std::make_shared<SubInstruction>(SubInstruction(1, "inmediate")));
  } else if (instruction.find("jump") != std::string::npos) {
    instructions.push_back(std::make_shared<JumpInstruction>(JumpInstruction(1, "inmediate")));
  } else if (instruction.find("jzero") != std::string::npos) {
    instructions.push_back(std::make_shared<JzeroInstruction>(JzeroInstruction(1, "inmediate")));
  } else if (instruction.find("halt") != std::string::npos) {
    instructions.push_back(std::make_shared<HaltInstruction>(HaltInstruction()));
  } else if (instruction.find("read") != std::string::npos) {
    instructions.push_back(std::make_shared<ReadInstruction>(ReadInstruction(1, "inmediate")));
  } else if (instruction.find("write") != std::string::npos) {
    instructions.push_back(std::make_shared<ReadInstruction>(ReadInstruction(1, "inmediate")));
  } else if (instruction.find("jgtz") != std::string::npos) {
    instructions.push_back(std::make_shared<JgtzInstruction>(JgtzInstruction(1, "inmediate")));
  } else {
    std::cout << "Error: instruction not found" << std::endl;
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

void ProgramMemory::executeInstructions() {
  for (int i = 0; i < instructions.size(); i++) {
    instructions[i]->execute();
  }
}