

#ifndef INPUT_UNIT_H
#define INPUT_UNIT_H

#include <iostream>
#include <vector>

class InputUnit {
 public:
  InputUnit() = default;
  InputUnit(std::vector<int> inputMemory) : inputMemory_(inputMemory) {}

  int getHead() const { return head_; }
  int getValue() { 
    return inputMemory_[head_++];
  }
  void incrementHead() { head_++; }

  void setMemory(std::vector<int> inputMemory) { inputMemory_ = inputMemory; }

 private:
  std::vector<int> inputMemory_;
  int head_ = 0;
};

#endif

