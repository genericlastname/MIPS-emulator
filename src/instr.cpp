#include "instr.h"

int* create_registers() {
  // create an array to hold registers
  int* r = new int[33];
  return r;
}

void add_op(int* regs, int rd, int rs, int rt) {
  // add register rs to rt and store the result in rd
  *(regs+rd) = *(regs+rs) + *(regs+rt);
}

void sub_op(int* regs, int rd, int rs, int rt) {
  // sub register rs and rt and store the result in rd
  *(regs+rd) = *(regs+rs) - *(regs+rt);
}

void and_op(int* regs, int rd, int rs, int rt) {
  *(regs+rd) = *(regs+rs) & *(regs+rt);
}

void or_op(int* regs, int rd, int rs, int rt) {
  *(regs+rd) = *(regs+rs) & *(regs+rt);
}
