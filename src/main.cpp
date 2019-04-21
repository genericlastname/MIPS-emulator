#include <iostream>
#include <stdio.h>
#include "instr.h"

void show(int* regs) {
  using namespace std;

  for (int i=0; i<32; i+=4) {
    printf("%i: %i\t %i: %i\t %i: %i\t %i: %i\n",
            i, regs[i], i+1, regs[i+1], i+2, regs[i+2], i+3, regs[i+3]);
  }
}

int main() {
  using namespace std;

  int* mem = create_memory();
  int* regs = create_registers();
  regs[0] = 13;
  regs[1] = 14;

  add_op(regs, 2, 0, 1);
  or_op(regs, 16, 0, 2);
  cout << "Regs:" << endl;
  show(regs);

  cout << "Mem" << endl;
  sw_op(regs, mem, 1, 2, 5);
  show(mem);
  return 0;
}
