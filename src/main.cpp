#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "instr.h"
#include "convert.h"
#include "interactive.h"

int main(int argc, char **argv) {
  using namespace std;

  int* mem = create_memory();
  int* regs = create_registers();

  if (argc == 1) {
    string input;
    bool running = true;

    while (running) {
      cout << ">> ";
      cin >> input;
      if (interactive(input, regs, mem) == 1) {
        running = false;
      }
    }
  }

  else if (argc == 2) {
    // load from file
    ifstream infile;
    infile.open(argv[1]);
    string line;
    if (infile.is_open()) {
      while (getline(infile, line)) {
        interactive(line, regs, mem);
      }
      infile.close();
      
      cout << "Registers:" << endl;
      show(regs);
      cout << "\nMemory" << endl;
      show(mem, true);
    }
    else cout << "File not found" << endl;
  }
}
