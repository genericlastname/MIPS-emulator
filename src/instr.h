#ifndef _INSTR_H_
#define _INSTR_H_

int* create_registers();

// r format
void add_op(int*, int, int, int);
void sub_op(int*, int, int, int);
void and_op(int*, int, int, int);
void or_op(int*, int, int, int);

#endif
