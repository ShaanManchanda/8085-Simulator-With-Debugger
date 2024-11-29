#ifndef LOADING
#define LOADING

#include <map>
#include <string>

#include "register.h"
#include "utils.h"

using namespace std;

string itos(int num);
void MOV(register_8bit &R1, register_8bit &R2);
void MVI(register_8bit &R, int immediateData);
void LXI(register_8bit &RH, register_8bit &RL, int immediateData);
void LDA(register_8bit &A, int immediateAddress, map<int, string> &mem);
void STA(register_8bit &A, int immediateAddress, map<int, string> &mem);
void LHLD(register_8bit &H, register_8bit &L, int immediateAddress, map<int, string> &mem);
void SHLD(register_8bit &H, register_8bit &L, int immediateAddress, map<int, string> &mem);
void STAX(register_8bit &A, register_8bit &RH, register_8bit &RL, map<int, string> &mem);
void SET(int immediateAddress, int immediateData, map<int, string> &mem);
void XCHG(register_8bit &H, register_8bit &L, register_8bit &D, register_8bit &E);

#endif // LOADING
