

#include "data-memory.h"

void DataMemory::printRegisters() {
  for (int i = 0; i < dataMemory_.size(); i++) {
    std::cout << "Register " << i << ": ";
    for (int j = 0; j < dataMemory_[i].size(); j++) {
      std::cout << dataMemory_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}