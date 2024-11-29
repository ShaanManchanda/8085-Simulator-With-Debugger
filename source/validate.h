#ifndef VALIDATE
#define VALIDATE
#include <regex>
#include <string>
#include <map>

#include "utils.h"

using namespace std;

bool validateAndUpdateProgramCounter(map<int, string>::iterator &PC);
bool validateCommand(string &command);
bool validateData(string &data);
bool validateMemory(map<int, string> &memory);

#endif // VALIDATE
