#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void DCX(string arg,string registers[],bool flag[]){

	int length = arg.length();
	if(length == 1){
	
		if(validateRegister(arg)){
			
			int registerID = registerNumber(arg);
			if(registerID == 0 || registerID == 2 || registerID == 4){
			
				string data16bit = "";
				string temporary = "";
				string s1 = "";
				string s2 = "";
				if(validateData(registers[registerID]) == true && validateData(registers[registerID+1]) == true){
					
					data16bit = data16bit + registers[registerID] + registers[registerID + 1];
					decreaseAddress(data16bit);
					temporary = data16bit;
					 s1 = s1 + temporary[0] + temporary[1];		
					 s2 = s2 + temporary[2] + temporary[3];
					 registers[registerID] = s1; 
					 registers[registerID+1] = s2;
				}
				else{
					cout<<"Error: "<<arg<<"\nInvalid data content\nThe program will quit\n";
					exit(0);
					/*Error:Invalid data content in registers*/
				}
			}
			else{
				cout<<"Error: "<<arg<<"\nInvalid register pair\nThe program will quit\n";
				exit(0);
				/*Error:Invaid register pair*/
			}
		}
		else{
			cout<<"Error: "<<arg<<"\nInvalid register content\nThe program will quit\n";
			exit(0);
			/*Error:Invalid register content*/ 
		}
	}
	else{
		cout<<"Error: "<<arg<<"\nInvalid input arguments\nThe program will quit\n";
		exit(0);
		/*Error:Invalid Input Argument*/
	}
}