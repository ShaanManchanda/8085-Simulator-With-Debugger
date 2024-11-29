#include "register.h"
#include "utils.h"

using namespace std;

void ADD(register_8bit &A, register_8bit &R, register_8bit &F)
{
    if(A.val + R.val > 0xff)
        setcarry(F);
    else
        resetcarry(F);
    if((A.val & 0xf) + (R.val & 0xf) > 0xf)
        setauxiliary(F);
    else
        resetauxiliary(F);
    A.val=A.val + R.val;
    if(A.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((A.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, A.val);
}

void ADI(register_8bit &A, int immediateData, register_8bit &F)
{
    if(A.val + immediateData > 0xff)
        setcarry(F);
    else
        resetcarry(F);
    if((A.val & 0xf) + (immediateData & 0xf) > 0xf)
        setauxiliary(F);
    else
        resetauxiliary(F);
    A.val=A.val + immediateData;
    if(A.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((A.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, A.val);
}

void SUB(register_8bit &A, register_8bit &R, register_8bit &F)
{
    if(A.val - R.val < 0x00)
        setcarry(F);
    else
        resetcarry(F);
    A.val=A.val - R.val;
    if(A.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((A.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, A.val);
}

void INR(register_8bit &R, register_8bit &F)
{
    R.val++;
    if(R.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((R.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, R.val);
}

void DCR(register_8bit &R, register_8bit &F)
{
    R.val--;
    if(R.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((R.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, R.val);
}

void INX(register_8bit &RH, register_8bit &RL)
{
    int temp=0x100 * RH.val + RL.val;
    temp++;
    RH.val=temp/0x100;
    RL.val=temp%0x100;
}

void DCX(register_8bit &RH, register_8bit &RL)
{
    int temp=0x100 * RH.val + RL.val;
    temp--;
    RH.val=temp/0x100;
    RL.val=temp%0x100;
}

void DAD(register_8bit &H, register_8bit &L, register_8bit &RH, register_8bit &RL, register_8bit &F)
{
    int temp=(0x100 * RH.val + RL.val) + (0x100 * H.val + L.val);
    H.val=temp/0x100;
    L.val=temp%0x100;
    if(temp > 0xffff)
        setcarry(F);
    else
        resetcarry(F);
}

void SUI(register_8bit &A, int immediateData, register_8bit &F)
{
    if(A.val - immediateData < 0)
        setcarry(F);
    else
        resetcarry(F);
    A.val=A.val - immediateData;
    if(A.val == 0)
        setzero(F);
    else
        resetzero(F);
    if((A.val & 0b10000000) == 0b10000000)
        setsign(F);
    else
        resetsign(F);
    checkparity(F, A.val);
}
