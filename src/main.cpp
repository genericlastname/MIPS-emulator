#include <iostream>
#include "instr.h"

int main() {
  int* regs = create_registers();
  regs[0] = 13;
  regs[2] = 14;

  add_op(regs, 1, 0, 2);
  or_op(regs, 16, 0, 2);
  std::cout << regs[1] << std::endl;
  std::cout << regs[16] << std::endl;

  return 0;
}
