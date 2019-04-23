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

vector<string> getinstr(const string& bininput) {
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
    
    vector<string> instr{"r", rformat[funct], rd, rs, rt};
    return instr;
  }
  else {
    // if the instr is I-Format
    string rs, rt, imm;
    rs = bininput.substr(6, 5);
    rt = bininput.substr(11, 5);
    imm = bininput.substr(16, 16);

    map<string, string> iformat = {
      { "100011", "lw" },
      { "101011", "sw" },
      { "000100", "beq" },
      { "000101", "bne" },
      { "001000", "addi" },
      };

    vector<string> instr{"i", iformat[opcode], rs, rt, imm};
    return instr;
  }
}
