#ifndef _INSTR_H_
#define _INSTR_H_

int* create_registers();
int* create_memory();

// r format rd, rs, rt
void add_op(int*, int, int, int);
void sub_op(int*, int, int, int);
void and_op(int*, int, int, int);
void or_op(int*, int, int, int);

// i format rs, rt, offset
void lw_op(int*, int*, int, int, int);
void sw_op(int*, int*, int, int, int);
void addi_op(int*, int, int, int);

// misc interactive mode commands
void show(const int* regs, const int r=-1);

#endif
