#include <iostream>
#include <stdio.h>
#include "instr.h"
#include "convert.h"

void show(int* regs) {
  for (int i=0; i<32; i+=4) {
    printf("%i: %i\t %i: %i\t %i: %i\t %i: %i\n",
            i, regs[i], i+1, regs[i+1], i+2, regs[i+2], i+3, regs[i+3]);
  }
}

int main() {
  using namespace std;

  int* mem = create_memory();
  int* regs = create_registers();
  regs[7] = 13;
  regs[3] = 14;

  string bin = hexbin("00e32822");
  cout << bin << endl;
  string* instr = getinstr(bin);
  cout << instr[1] << endl;
}
