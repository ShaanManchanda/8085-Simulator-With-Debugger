#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void DCR(string arg,string registers[],string accumulator,bool flag[],map<string,string>&memory){

	int length = arg.length();
	if(length == 1){
	
		if(validateRegister(arg)){
		
			if(arg != "M"){
				
				/*Performs INR on a register*/

                if(arg=="A"){
                    accumulator = hexaSub(accumulator,"01",flag,false);
					return;
                }
				int registerID = registerNumber(arg);
				registers[registerID] = hexaSub(registers[registerID],"01",flag,false);
			}
			else{
				/*Performs DCR on HL pair*/
				string address = "";
				address = address + registers[4] + registers[5];
				if(validateAddress(address)){
					memory[address] = hexaSub(memory[address],"01",flag,false);
				}
				else{
					cout<<"Error: "<<arg<<"\nInvalid register details\nThe program will quit\n";
					exit(0);
					/*Error:Address out of bounds*/
				}
			}
		}
		else{
			cout<<"Error: "<<arg<<"\nInvalid register\nThe program will quit\n";
			exit(0);
			/*Error:Invalid Register*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid argument\nThe program will quit\n";
				exit(0);
		/*Error: Invalid argument type*/
	}
}