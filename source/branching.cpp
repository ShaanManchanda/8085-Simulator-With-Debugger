#include <map>
#include <iterator>

#include "register.h"

using namespace std;

void JMP(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData)
{
    PC=memory.find(immediateData);
}

void JC(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F)
{
    if((F.val & 0b00000001) == 0b00000001)
    {
        PC=memory.find(immediateData);
    }
    else
    {
        PC++;
        PC++;
        PC++;
    }
}

void JNC(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F)
{
    if((F.val & 0b00000001) == 0b00000000)
    {
        PC=memory.find(immediateData);
    }
    else
    {
        PC++;
        PC++;
        PC++;
    }
}

void JZ(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F)
{
    if((F.val & 0b01000000) == 0b01000000)
    {
        PC=memory.find(immediateData);
    }
    else
    {
        PC++;
        PC++;
        PC++;
    }
}

void JNZ(map<int, string> &memory, map<int, string>::iterator &PC, int &immediateData, register_8bit &F)
{
    if((F.val & 0b01000000) == 0b00000000)
    {
        PC=memory.find(immediateData);
    }
    else
    {
        PC++;
        PC++;
        PC++;
    }
}
