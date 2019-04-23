#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "instr.h"
#include "convert.h"

int main() {
  using namespace std;

  int* mem = create_memory();
  int* regs = create_registers();

  bool running = true;
  string input;
  while (running) {
    // prompt
    cout << ">> ";
    cin >> input;

    if (input == "reg" || input == "regs") {
      show(regs);
    }
    else if (input == "mem") {
      show(mem);
    }
    else if (input == "quit" || cin.eof()) {
      running = false;
    }
    else if (isxdigit(input[0])) {
      string bin = hextobin(input);
      vector<string> instr = getinstr(bin);
      // print the full instruction
      cout << bin << endl;

      if (instr[0] == "r") {
        int rd, rs, rt;
        rd = bintoint(instr[2]);
        rs = bintoint(instr[3]);
        rt = bintoint(instr[4]);

        cout << instr[1] << " $" << rd << ", $" << rs << ", $" << rt << endl;

        // run commands
        if (instr[1] == "add") {
          add_op(regs, rd, rs, rt);
        }
        else if (instr[1] == "sub") {
          sub_op(regs, rd, rs, rt);
        }
        else if (instr[1] == "and") {
          and_op(regs, rd, rs, rt);
        }
        else if (instr[1] == "or") {
          or_op(regs, rd, rs, rt);
        }
      }
      else if (instr[0] == "i") {
        int rs, rt, imm;
        rs = bintoint(instr[2]);
        rt = bintoint(instr[3]);
        imm = bintoint(instr[4]);

        if (instr[1] == "lw" || instr[1] == "sw") {
          // print diff format for lw and sw
          cout << instr[1] << " $" << rt << ", " << imm << "($" << rs << ")" << endl;
        }
        else {
          // any other i format instruction
          cout << instr[1] << " $" << rt << ", $" << rs << ", " << imm << endl;
        }

        // run commands
        if (instr[1] == "lw") {
          lw_op(regs, mem, rs, rt, imm);
        }
        else if (instr[1] == "sw") {
          sw_op(regs, mem, rs, rt, imm);
        }
        else if (instr[1] == "beq") {
          /* beq_op(regs, rs, rt, imm); */
        }
        else if (instr[1] == "bne") {
          /* bne(regs, rs, rt, imm); */
        }
        else if (instr[1] == "addi") {
          addi_op(regs, rt, rs, imm);
        }
      }
    }
    else {
      cout << "Invalid command or hex string" << endl;
    }
  }
}
        
