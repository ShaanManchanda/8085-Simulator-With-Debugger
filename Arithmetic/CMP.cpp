#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void CMP(string arg1, string registers[], string &accumulator, bool flag[], map<string, string> &memory)
{
    int l1 = arg1.length();
    if (l1 == 1)
    {
        if (arg1 == "M")
        {
            string address = registers[4] + registers[5];
            if (accumulator < memory[address])
            {
                flag[0] = true;
            }
            else if (accumulator == memory[address])
            {
                flag[6] = true;
                // cout<<"zero set\n";
            }
            else
            {
                // cout<<"both reset\n";
                flag[0] = false;
                flag[6] = false;
            }
        }
        else if (validateRegister(arg1))
        {
            int index = registerNumber(arg1);
            if (accumulator < registers[index])
            {
                // cout<<"carry set\n";
                flag[0] = true;
            }
            else if (accumulator == registers[index])
            {
                // cout<<"zero set\n";
                flag[6] = true;
            }
            else
            {
                // cout<<"both reset\n";
                flag[0] = false;
                flag[6] = false;
            }
        }
        else
        {

            cout << "Error: " << arg1 << "\nInvalid registers\nThe program will quit\n";
            exit(0);
        }
    }
    else
    {

        cout << "Error: " << arg1 << "\nInvalid argument\nThe program will quit\n";
        exit(0);
    }
}