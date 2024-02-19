
#ifndef OUTPUT_UNIT_H
#define OUTPUT_UNIT_H

#include <iostream>
#include <vector>
#include <fstream>

class OutputUnit {
 public:
  OutputUnit() = default;
  OutputUnit(std::string outputFileName) : outputFileName_(outputFileName) {}

  void setOutputFileName(std::string outputFileName) { outputFileName_ = outputFileName; }

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

  void writeToFile() {
    std::ofstream file(outputFileName_);
    if (file.is_open()) {
      for (int i = 0; i < outputMemory_.size(); i++) {
        file << outputMemory_[i] << " ";
      }
      file.close();
    } else {
      std::cout << "Unable to open file";
    }
  }

 private:
  std::string outputFileName_;
  std::vector<int> outputMemory_;
  int head_ = 0;
};

#endif