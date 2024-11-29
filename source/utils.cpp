#include <string>
#include <sstream>

#include "register.h"

using namespace std;

void setcarry(register_8bit &F)
{
    F.val=F.val | 0b00000001;
}

void resetcarry(register_8bit &F)
{
    F.val=F.val & 0b11111110;
}

void setzero(register_8bit &F)
{
    F.val=F.val | 0b01000000;
}

void resetzero(register_8bit &F)
{
    F.val=F.val & 0b10111111;
}

void setauxiliary(register_8bit &F)
{
    F.val=F.val | 0b00010000;
}

void resetauxiliary(register_8bit &F)
{
    F.val=F.val & 0b11101111;
}

void checkparity(register_8bit &F, int val)
{
    int setBits=0;
    val=val & 0xff;
    for (setBits=0; val!=0; val=val>>1)
    {
        setBits+=val&1;
    }
    if(setBits%2==0)
        F.val=F.val | 0b00000100;
    else
        F.val=F.val & 0b11111011;
}

void setsign(register_8bit &F)
{
    F.val=F.val ^ 0b10000000;
}

void resetsign(register_8bit &F)
{
    F.val=F.val & 0b01111111;
}

//converts number to hex string
string itos(int num)
{
    stringstream tempStream;
    tempStream<<hex<<num;
    return tempStream.str();
}//converts number to hex string

int stohex(string s)
{
    stringstream tempStream;
    tempStream<<s;
    int hexNum;
    tempStream>>hex>>hexNum;
    return hexNum;
}

//parses command from the input
string parseCommand(string input)
{
    int i;
    for(i=0; input[i]!=0; i++)
        if(input[i]==' ')
            break;
    return input.substr(0, i);
}
