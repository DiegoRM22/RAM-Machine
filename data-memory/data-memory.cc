

#include "data-memory.h"

void DataMemory::printRegisters() {
  for (int i = 0; i < dataMemory_.size(); i++) {
    std::cout << "Register " << i << ": " << dataMemory_[i] << std::endl;
  }
}