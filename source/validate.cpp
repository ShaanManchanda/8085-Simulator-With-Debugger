#include <regex>
#include <string>
#include <map>
#include <iostream>

#include "utils.h"

using namespace std;

bool validateAndUpdateProgramCounter(map<int, string>::iterator &PC)
{
    map<string, int> commands= {
        {"MVI", 2}, {"ADI", 2}, {"SUI", 2}, {"LXI", 3}, {"JMP", 3},
        {"JC", 3}, {"JNC", 3}, {"JZ", 3}, {"JNZ", 3}, {"LDA", 3},
        {"STA", 3}, {"LHLD", 3}, {"SHLD", 3}, {"SET", 4}
    };
    auto search = commands.find(parseCommand(PC->second));
    PC++;
    if(search != commands.end())
    {
        for(int i=0; i<search->second-1; i++,PC++)
            if(PC->second != " ")
                return false;
    }
    return true;
}

bool validateData(string &data)
{
    regex hexDataRegex("[0-9a-fA-F][0-9a-fA-F]");
    return regex_match(data, hexDataRegex);
}

bool validateCommand(string &command)
{
    regex addressCommands("(LHLD|SHLD|LDA|STA|JZ|JNZ|JC|JNC|JMP) [0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]");
    regex oneRegisterCommands("(ADD|SUB|DCR|INR) [A-E|H|L]");
    regex higherRegisterCommands("(INX|DCX|DAD) [A-E|H|L]");
    regex $8bitdataCommands("(ADI|SUI) [0-9a-fA-F][0-9a-fA-F]");
    regex MOVCommand("MOV [A-E|H|L],[A-E|H|L]");
    regex SETCommand("SET [0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F],[0-9a-fA-F][0-9a-fA-F]");
    regex implicit("CMA|HLT|XCHG");
    regex MVICommand("MVI [A-E|H|L] [0-9a-fA-F][0-9a-fA-F]");
    regex LXICommand("LXI [B|D|H] [0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]");
    regex STAXCommand("STAX [B|D|H]");

    //returns true if the input command matches any one of the regular expressions
    return regex_match(command, addressCommands) || regex_match(command, oneRegisterCommands) || regex_match(command, higherRegisterCommands)
        || regex_match(command, $8bitdataCommands) || regex_match(command, MOVCommand) || regex_match(command, SETCommand)
        || regex_match(command, implicit) || regex_match(command, MVICommand) || regex_match(command, LXICommand)
        || regex_match(command, STAXCommand);
}

bool validateMemory(map<int, string> &memory)
{
    bool hasHLT=false;
    map<int, string>::iterator PC=memory.begin();
    while(PC!=memory.end())
    {
        if(PC->first > 0xFFFF)
        {
            cout<<"Memory out of bounds"<<'\n';
            return false;
        }
        if(PC->second == "HLT")
            hasHLT=true;
        if(validateCommand(PC->second) == false && validateData(PC->second) == false)
        {
            cout<<"Syntax error at "<<hex<<PC->first<<'\n';
            return false;
        }
        if(validateAndUpdateProgramCounter(PC)==false)
        {
            cout<<"Syntax error at "<<hex<<PC->first<<'\n';
            return false;
        }
    }
    if(!hasHLT)
        cout<<"No HLT in the provided code"<<'\n';
    return hasHLT;
}
