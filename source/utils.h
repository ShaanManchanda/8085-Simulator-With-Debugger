#ifndef UTILITIES
#define UTILITIES

#include <string>
#include <sstream>

#include "register.h"

using namespace std;

void setcarry(register_8bit &F);
void resetcarry(register_8bit &F);
void setzero(register_8bit &F);
void resetzero(register_8bit &F);
void setauxiliary(register_8bit &F);
void resetauxiliary(register_8bit &F);
void checkparity(register_8bit &F, int val);
void setsign(register_8bit &F);
void resetsign(register_8bit &F);
string itos(int num);
int stohex(string s);
string parseCommand(string input);

#endif // UTILITIES
