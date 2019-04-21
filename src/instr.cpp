#include "instr.h"

int* create_registers() {
  // create an array to hold registers
  int* r = new int[33];
  return r;
}

int* create_memory() {
  // create an array to hold memory
  int* m = new int[32];
  return m;
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

void lw_op(int* regs, int* mem, int rs, int rt, int offset) {
  *(regs+rt) = *(mem+( *(regs+rs)+offset) );
}

void sw_op(int* regs, int* mem, int rs, int rt, int offset) {
  *(mem+( *(regs+rs)+offset) ) = *(regs+rt);
}
