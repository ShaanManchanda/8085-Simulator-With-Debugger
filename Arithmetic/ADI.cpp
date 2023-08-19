#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void ADI(string arg, string &accumulator,bool flag[]){
	int length = arg.length();
	if(length == 2){
		if(validateData(arg)){
			/*Performs immediate addition and stores in accumulator*/
			accumulator = hexaAdd(arg,accumulator,flag,true);
		}
		else{
			cout<<"Error: "<<arg<<"\nInvalid data content\nThe program will quit\n";
			exit(0);
			/*Error message of invalid data content*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid data size\nThe program will quit\n";
		exit(0);
		/*Error message of invalid data size*/
	}
	
}