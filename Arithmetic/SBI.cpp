#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void SBI(string arg,string & accumulator, string registers[],bool flag[]){

	int length = arg.length();
	if(length == 2){
		if(validateData(arg)){
			/*Performs immediate subtraction and stores in accumulator*/
		accumulator = hexaSub(arg,accumulator,flag,true);
		}
		else{
			
			cout<<"Error: "<<arg<<"\n";
			cout<<"This is an invalid data\n";
			exit(0);
			/*Error message of invalid data content*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\n";
		cout<<"You have tried to enter invalid data\nThe program will quit\n";
		exit(0);
		/*Error message of invalid data size*/
	}
	
}