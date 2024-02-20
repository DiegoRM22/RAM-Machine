
#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <iostream>
#include <vector>

class DataMemory {
 public:
  DataMemory() : dataMemory_(10, std::vector<int>(10, 0)) {}
  void write(int address, int value, int position = 0) { dataMemory_[address][position] = value; }
  int read(int address, int position = 0) { return dataMemory_[address][position]; }
  void printRegisters();
  void setRegister(int address, int value, int position = 0) {
    if (address >= dataMemory_.size()) {
      dataMemory_.resize(address + 1, std::vector<int>(10, 0));
      //std::cout << "Resizing data memory to " << address + 1 << std::endl;
    }
    std::cout << "Setting register " << address << " [" << position << " to " << value << std::endl;
    dataMemory_[address][position] = value;
    std::cout << "Register " << address << " [" << position << "] set to " << dataMemory_[address][position] << std::endl;
  }
  int getRegister(int address, int position = 0) { return dataMemory_[address][position]; }

 private:
  std::vector<std::vector<int>> dataMemory_;
};

#endif