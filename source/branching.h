#ifndef BRANCHING
#define BRANCHING

#include <map>
#include <iterator>

#include "register.h"

using namespace std;

void JMP(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData);
void JC(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F);
void JNC(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F);
void JZ(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F);
void JNZ(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F);

#endif // BRANCHING

