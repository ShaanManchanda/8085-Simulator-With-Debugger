#ifndef ARITH
#define ARITH

#include "register.h"
#include "utils.h"

using namespace std;

void ADD(register_8bit &A, register_8bit &R, register_8bit &F);
void ADI(register_8bit &A, int immediateData, register_8bit &F);
void SUB(register_8bit &A, register_8bit &R, register_8bit &F);
void INR(register_8bit &R, register_8bit &F);
void DCR(register_8bit &R, register_8bit &F);
void INX(register_8bit &RH, register_8bit &RL);
void DCX(register_8bit &RH, register_8bit &RL);
void DAD(register_8bit &H, register_8bit &L, register_8bit &RH, register_8bit &RL, register_8bit &F);
void SUI(register_8bit &A, int immediateData, register_8bit &F);

#endif // ARITH
