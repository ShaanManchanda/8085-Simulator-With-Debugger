#include <map>
#include <string>

#include "register.h"
#include "utils.h"

using namespace std;

void MOV(register_8bit &R1, register_8bit &R2)
{
    R1.val=R2.val;
}

void MVI(register_8bit &R, int immediateData)
{
    R.val=immediateData;
}

void LXI(register_8bit &RH, register_8bit &RL, int immediateData)
{
    RH.val=immediateData / 0x100;
    RL.val=immediateData % 0x100;
}

void LDA(register_8bit &A, int immediateAddress, map<int, string> &mem)
{
    auto search=mem.find(immediateAddress);
        A.val=stohex(search->second);
}

void STA(register_8bit &A, int immediateAddress, map<int, string> &mem)
{
    mem[immediateAddress]=itos(A.val);
}

void LHLD(register_8bit &H, register_8bit &L, int immediateAddress, map<int, string> &mem)
{
    auto search=mem.find(immediateAddress);
    L.val=stohex(search->second);
    search++;
    H.val=stohex(search->second);
}

void SHLD(register_8bit &H, register_8bit &L, int immediateAddress, map<int, string> &mem)
{
    mem[immediateAddress]=itos(L.val);
    mem[immediateAddress+1]=itos(H.val);
}

void STAX(register_8bit &A, register_8bit &RH, register_8bit &RL, map<int, string> &mem)
{
    int destinationAddress=RH.val*0X100+RL.val;
    mem[destinationAddress]=itos(A.val);
}

void SET(int immediateAddress, int immediateData, map<int, string> &mem)
{
    mem[immediateAddress]=itos(immediateData);
}

void XCHG(register_8bit &H, register_8bit &L, register_8bit &D, register_8bit &E)
{
    int temp=H.val;
    H.val=D.val;
    D.val=temp;
    temp=L.val;
    L.val=E.val;
    E.val=temp;
}
