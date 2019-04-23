#include "convert.h"

using namespace std;

string hextobin(const string& hexinput) {
  stringstream out;
  out << hex << hexinput;
  unsigned n;
  out >> n;
  bitset<32> b(n);

  return (b.to_string());
}

int bintoint(const string& bininput) {
  int value = stoi(bininput, 0, 2);
  return value;
}


string* getinstr(const string& bininput) {
  string opcode = bininput.substr(0, 6);

  if (opcode == "000000") {
    // if the instr is R-Format
    string rd, rs, rt, funct;
    rs = bininput.substr(6, 5);
    rt = bininput.substr(11, 5);
    rd = bininput.substr(16, 5);
    funct = bininput.substr(26, 6);

    map<string, string> rformat = {
      { "100000", "add" },
      { "100010", "sub" },
      { "100100", "and" },
      { "100101", "or" },
      };
    
    string instr[] = {"r", rformat[funct], rd, rs, rt};
    return instr;
  }
}
