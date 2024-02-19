
#include <algorithm>
#include <string>

#include "program-memory.h"
#include "../instruction/read-instruction/read-instruction.h"
#include "../instruction/load-instruction/load-instruction.h"
#include "../instruction/store-instruction/store-instruction.h"
#include "../instruction/div-instruction/div-instruction.h"
#include "../instruction/mul-instruction/mul-instruction.h"
#include "../instruction/add-instruction/add-instruction.h"
#include "../instruction/sub-instruction/sub-instruction.h"
#include "../instruction/jump-instruction.h"
#include "../instruction/jzero-instruction.h"
#include "../instruction/jgtz-instruction.h"
#include "../instruction/halt-instruction.h"
#include "../instruction/write-instruction/write-instruction.h"


#define STORE = "STORE"

void ProgramMemory::findLabels(const std::string& program) {
  std::string line;
  std::ifstream ramProgramFile(program);
  int lineCounter = 0;
  while (std::getline(ramProgramFile, line)) {
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    if (line[0] != '#' && !line.empty()) {
      // Revisar que la linea no sean solo espacios en blanco
      
      //std::cout << "Line: " << line << std::endl;
      if (line.find(':') != std::string::npos) {
        // Split the line in two parts: label and instruction
        std::string label = line.substr(0, line.find(':'));
        // Add the label and the line to the vector
        labels_.push_back(PairLabelLine(label, lineCounter));
      }
      lineCounter++;
    }
  }
}

ProgramMemory::ProgramMemory(std::string ramProgramFileName) {
  std::string line;
  std::ifstream ramProgramFile(ramProgramFileName);
  int lineCounter = 0;
  findLabels(ramProgramFileName);
  while (std::getline(ramProgramFile, line)) {
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    int operand = 0;
    std::string operandType = "direct";
    // Check if the line is a comment and if is not empty
    std::cout << "Line: " << line << std::endl;
    if (line[0] != '#' && !line.empty()) {
      // Check if the line is a label -> there's a : in the line
      std::cout << " entra aqui" << std::endl;
      std::string instruction;
      if (line.find(':') != std::string::npos) {
        instruction = line.substr(line.find(':') + 1, line.size());
      } else {
        line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        instruction = line;
      }
      instruction.erase(instruction.begin(), std::find_if(instruction.begin(), instruction.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
      instructions_.push_back(instruction);
      std::string auxInstruction = instruction;
      std::string keyChar = " ";
      if (instruction.find("=") != std::string::npos) {
        keyChar = "=";
        //operand = std::stoi(instruction.substr(instruction.find("=") + 1, instruction.size()));
        operandType = "inmediate";
        //instruction = instruction.substr(0, instruction.find("="));
      } else if (instruction.find("*") != std::string::npos) {
        keyChar = "*";
        operandType = "indirect";
      } // Aquí tenemos que trabajar con la instrucción directa o instrucciones de salto.
        instruction = instruction.substr(0, instruction.find(keyChar));
        auxInstruction.erase(0, instruction.size() + 1);
        int position = 0;
        // La posicion esta entre los corchetes
        if (auxInstruction.find("[") != std::string::npos) {
          position = std::stoi(auxInstruction.substr(auxInstruction.find("[") + 1, auxInstruction.find("]") - 1));
          auxInstruction = auxInstruction.substr(0, auxInstruction.find("["));
          std::cout << "Position: " << position << std::endl;
        }
        //std::cout << "Operand string: " << auxInstruction << " de tamaño: " << auxInstruction.size() << std::endl;
        //printLabels();
        // convertir a minusculas la instruccion
        std::transform(instruction.begin(), instruction.end(), instruction.begin(), ::tolower);
        if (instruction == "jump" || instruction == "jzero" || instruction == "jgtz") {
          PairLabelLine pairLabelLine(auxInstruction, getLabelLine(auxInstruction));
          checkTypeInstruction(instruction, 0, "inmediate", pairLabelLine);
          continue;
        }
        if (auxInstruction.length() > 0) {
          operand = std::stoi(auxInstruction);
        }
      checkTypeInstruction(instruction, operand, operandType, PairLabelLine(), position);
      program_ += instruction + "\n";
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

void ProgramMemory::checkTypeInstruction(const std::string& instruction, const int instructionOPerand, const std::string& operandType,
                                         const PairLabelLine& labelLine, int position) {
  // convertimos la instruccion a minusculas
  std::cout << "Checking type of instruction: " << instruction << std::endl;
  // Obtener el operando de la instruccion
  if (instruction.find("store") != std::string::npos) {
    instructions.push_back(std::make_shared<StoreInstruction>(StoreInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("load") != std::string::npos) {
    instructions.push_back(std::make_shared<LoadInstruction>(LoadInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("store") != std::string::npos) {
    instructions.push_back(std::make_shared<StoreInstruction>(StoreInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("div") != std::string::npos) {
    instructions.push_back(std::make_shared<DivInstruction>(DivInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("mul") != std::string::npos) {
    instructions.push_back(std::make_shared<MulInstruction>(MulInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("add") != std::string::npos) {
    instructions.push_back(std::make_shared<AddInstruction>(AddInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("sub") != std::string::npos) {
    instructions.push_back(std::make_shared<SubInstruction>(SubInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("jump") != std::string::npos) {
    instructions.push_back(std::make_shared<JumpInstruction>(JumpInstruction(labelLine)));
  } else if (instruction.find("jzero") != std::string::npos) {
    instructions.push_back(std::make_shared<JzeroInstruction>(JzeroInstruction(labelLine)));
  } else if (instruction.find("halt") != std::string::npos) {
    instructions.push_back(std::make_shared<HaltInstruction>(HaltInstruction()));
  } else if (instruction.find("read") != std::string::npos) {
    instructions.push_back(std::make_shared<ReadInstruction>(ReadInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("write") != std::string::npos) {
    instructions.push_back(std::make_shared<WriteInstruction>(WriteInstruction(instructionOPerand, operandType, position)));
  } else if (instruction.find("jgtz") != std::string::npos) {
    instructions.push_back(std::make_shared<JgtzInstruction>(JgtzInstruction(labelLine)));
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

bool ProgramMemory::isALabel(const std::string& label) const {
  for (int i = 0; i < labels_.size(); i++) {
    if (labels_[i].getLabel() == label) {
      return true;
    }
  }
  return false;
}