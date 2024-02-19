
#ifndef OUTPUT_UNIT_H
#define OUTPUT_UNIT_H

#include <iostream>
#include <vector>

class OutputUnit {
 public:
  OutputUnit() = default;
  OutputUnit(std::string outputFileName) : outputFileName_(outputFileName) {}

  void write(const int value) {
    outputMemory_.resize(outputMemory_.size() + 1);
    outputMemory_[head_++] = value;
  }
  void incrementHead() { head_++; }

  void printMemory() {
    for (int i = 0; i < outputMemory_.size(); i++) {
      std::cout << outputMemory_[i] << " ";
    }
  }

 private:
  std::string outputFileName_;
  std::vector<int> outputMemory_;
  int head_ = 0;
};

#endif