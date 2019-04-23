#include <stdio.h>
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

void addi_op(int* regs, int rt, int rs, int imm) {
  *(regs+rt) = *(regs+rs) + imm;
}

void show(const int* regs, const int r) {
  if (r == -1) {
    for (int i=0; i<32; i+=4) {
      printf("%i:\t%04x\t %i:\t%04x\t %i:\t%04x\t %i:\t%04x\n",
              i, regs[i], i+1, regs[i+1], i+2, regs[i+2], i+3, regs[i+3]);
    }
  } 
  else if (r > -1) {
    printf("%i: %i\n", r, regs[r]);
  }
}
