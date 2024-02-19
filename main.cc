

#include <iostream>
#include <fstream>

#include "ram-machine/ram-machine.h"

// void Usage(int argc, char *argv[]) {
//   if (argc != 4) {
//     std::cerr << "Usage: " << argv[0] << " <ram-program-file> <input-file> <output-file>" << std::endl;
//     return 1;
//   }
//   std::ifstream ramProgramFile(argv[1]);
//   std::ifstream inputFile(argv[2]);
//   std::ofstream outputFile(argv[3]);
//   if (!ramProgramFile.is_open()) {
//     std::cerr << "Error: could not open file " << argv[1] << std::endl;
//     return 1;
//   }
//   if (!inputFile.is_open()) {
//     std::cerr << "Error: could not open file " << argv[2] << std::endl;
//     return 1;
//   }
//   if (!outputFile.is_open()) {
//     std::cerr << "Error: could not open file " << argv[3] << std::endl;
//     return 1;
//   }
// }


int main(int argc, char *argv[]) {
  std::string ramProgramFile(argv[1]);
  std::string inputFile(argv[2]);
  std::string outputFile(argv[3]);
  int debugOption = 0;
  if (argc == 5) {
    std::string debugOptionString(argv[4]);
    if (debugOptionString == "-d") {
      debugOption = 1;
    } else if (debugOptionString == "-dd") {
      debugOption = 2;
    }
  }

  RAMMachine ramMachine(ramProgramFile, inputFile, outputFile);
  ramMachine.runProgram(argv[1], debugOption);
  // RAMMachine ramMachine(ramProgramFile, inputFile, outputFile);
  // ramMachine.loadProgram(argv[1]);
  // ramMachine.run();

  return 0;
}