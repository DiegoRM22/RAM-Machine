

#ifndef INPUT_UNIT_H
#define INPUT_UNIT_H

#include <iostream>
#include <vector>
#include <fstream>
// Clase que representa la unidad de entrada de la máquina de Turing.
class InputUnit {
 public:
  InputUnit() = default;
  InputUnit(std::vector<int> inputMemory) : inputMemory_(inputMemory) {}

  int getHead() const { return head_; }
  int getValue() { 
    if (head_ == inputMemory_.size()) throw std::runtime_error("No more inputs available.");
    return inputMemory_[head_++];
  }
  void incrementHead() { head_++; }

  void setMemory(const std::vector<int>& inputMemory) { inputMemory_ = inputMemory; }
  void setMemory(const std::string& inputFileName) {
    std::ifstream file(inputFileName);
    if (file.is_open()) {
      int value;
      while (file >> value) {
        inputMemory_.push_back(value);
      }
      file.close();
    } else {
      std::cout << "Unable to open file";
    }
  }

  void printMemory() {
    for (int i = 0; i < inputMemory_.size(); i++) {
      std::cout << inputMemory_[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < inputMemory_.size(); i++) {
      if (i == head_ - 1) std::cout << " ^";
      else std::cout << "  ";
    }
    std::cout << std::endl;
    std::cout << "Cabeza: " << head_ << std::endl;
  }

 private:
  std::vector<int> inputMemory_;
  int head_ = 0;
};

#endif

