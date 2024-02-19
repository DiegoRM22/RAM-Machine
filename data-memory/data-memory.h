
#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <iostream>
#include <vector>

class DataMemory {
 public:
  DataMemory() : dataMemory_(10, 0) {}
  void write(int address, int value) { dataMemory_[address] = value; }
  int read(int address) { return dataMemory_[address]; }
  void printRegisters();
  void setRegister(int address, int value) { dataMemory_[address] = value; }
  int getRegister(int address) { return dataMemory_[address]; }

 private:
  std::vector<int> dataMemory_;
};

#endif