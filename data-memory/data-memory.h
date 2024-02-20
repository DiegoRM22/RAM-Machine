
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
    dataMemory_[address][position] = value;
  }
  int getRegister(int address, int position = 0) { return dataMemory_[address][position]; }
  int getVectorSize(int address) { return dataMemory_[address].size(); }

 private:
  std::vector<std::vector<int>> dataMemory_;
};

#endif