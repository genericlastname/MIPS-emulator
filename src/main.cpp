#include <iostream>
#include "instr.h"

using std::cout, std::endl;

int main() {
  int* regs = create_registers();
  regs[0] = 13;
  regs[2] = 14;

  add(regs, 1, 0, 2);
  cout << regs[1] << endl;
  return 0;
}
