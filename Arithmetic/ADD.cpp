#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void ADD(string arg1,string &accumulator,string registers[],bool flag[],map<string,string>&memory){
	
	int length=arg1.length();
	if(length == 1){
		if(validateRegister(arg1) || validateRegisterPair(arg1)){
			if(arg1 != "M"){
				/*Fetches index of register to access array string registers[]*/
				int registerID = registerNumber(arg1);
				/*Converting decimal value to string format and storing in accumulator*/
				accumulator = hexaAdd(registers[registerID],accumulator,flag,true);
			}
			else{                         
		
				/*Fetches data of HL pair*/
				string address = "";
				address = address + registers[4] + registers[5];
				if(validateAddress(address)){
				
					/*Converting decimal value to string format and storing in accumulator*/
					accumulator = hexaAdd(memory[address],accumulator,flag,true);				 
				}
				else{
					
					cout<<"Error: "<<arg1<<"\n";
					cout<<"Address out of bounds\nThe program will quit\n";
					exit(0);
					/*error message of address out of bounds*/
				}						
			}
		}
		else{
				
				cout<<"Error: "<<arg1<<"\nInvalid register details\nThe program will quit\n";
				exit(0);
			/*error of invalid register details*/
		}
	}
	else{
		
		cout<<"Error: "<<arg1<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
		/*Error message of invalid arguments*/
	}
}