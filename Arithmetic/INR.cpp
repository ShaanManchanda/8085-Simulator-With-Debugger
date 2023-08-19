#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void INR(string arg,string registers[],string &accumulator,bool flag[],map<string,string>&memory){

	int length = arg.length();
	if(length == 1){
	
		if(validateRegister(arg)){
		

        // If the argument is not M (memory)
			if(arg != "M"){
                //for accumulator
                if(arg=="A"){
                    accumulator = hexaAdd(accumulator,"01",flag,false);
                    return ;
                }

                // for other registers
                int registerID = registerNumber(arg);
				registers[registerID] = hexaAdd(registers[registerID],"01",flag,false); 
                
			}
			else{
				/*Performs DCR on HL pair*/
				string address = "";
				address = address + registers[4] + registers[5];
				if(validateAddress(address)){
					memory[address] = hexaAdd(memory[address],"01",flag,false);
				}
				else{
					
					cout<<"Error: "<<arg<<"\nAddress out of bounds\nThe program will quit\n";
					exit(0);
				}
			}
		}
		else{
			
			cout<<"Error: "<<arg<<"\nInvalid register details\nThe program will quit\n";
			exit(0);
			/*Error:Invalid Register*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid argument type\nThe program will quit\n";
		exit(0);
		/*Error: Invalid argument type*/
	}
}