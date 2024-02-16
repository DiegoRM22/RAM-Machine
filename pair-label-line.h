

#include <iostream>

class PairLabelLine {
 public:
  PairLabelLine() : label(""), line(-1) {}
  PairLabelLine(std::string label, int line) : label(label), line(line) {}
  int getLine() const { return line; }
  std::string getLabel() const { return label; }
 private:
  std::string label;
  int line;
};