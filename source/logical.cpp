#include "register.h"
#include "utils.h"

void CMA(register_8bit &A)
{
    A.val=~A.val;
}

void CMP(register_8bit A, register_8bit R, register_8bit &F)
{
    A.val=A.val-R.val;
    if(A.val<0) //set carry and sign and reset zero
    {
        F.val=F.val | 0b10000001;
        F.val=F.val & 0b10000001;
    }
    else if(A.val==0) //reset carry and sign and set zero
    {
        F.val=F.val | 0b01000000;
        F.val=F.val & 0b01000000;
    }
    else //reset all flags
        F.val=F.val & 0;
    checkparity(F, A.val); //check the parity
}
