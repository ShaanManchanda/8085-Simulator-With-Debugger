#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"
#include "../HeaderFiles/arithematic.h"

void DAD(string arg, string registers[], bool flag[]){
	int length = arg.length();
	if (length == 1)
	{
		if (validateRegister(arg))
		{
			int registerID = registerNumber(arg);
			if (registerID == 0 || registerID == 2 || registerID == 4)
			{
				string data16bit = "";
				string data16bitHL = "";
				string resultant = "";
				if (validateData(registers[registerID]) && validateData(registers[registerID + 1]) && validateData(registers[5]) && validateData(registers[5]))
				{

					data16bit = data16bit + registers[registerID] + registers[registerID];
					data16bitHL = data16bitHL + registers[4] + registers[5];
					int value16bit[4];
					int value16bitHL[4];
					int carry = 0;
					hexaToDecimal(arg, value16bit);
					hexaToDecimal(arg, value16bitHL);
					for (int i = 3; i >= 0; i--)
					{
						int value = value16bit[i] + value16bitHL[i] + carry;
						if (value >= 16)
							flag[0] = true;
						else
							flag[0] = false;
						carry = value / 16;
						value = value % 16;
						if (value >= 0 && value <= 9)
							resultant = (char)('0' + value) + resultant;
						else
						{
							switch (value)
							{

							case 10:
								resultant = "A" + resultant;
								break;
							case 11:
								resultant = "B" + resultant;
								break;
							case 12:
								resultant = "C" + resultant;
								break;
							case 13:
								resultant = "D" + resultant;
								break;
							case 14:
								resultant = "E" + resultant;
								break;
							case 15:
								resultant = "F" + resultant;
								break;
							}
						}
					}

					registers[4] = resultant[0] + resultant[1];
					registers[5] = resultant[2] + resultant[3];
				}
				else
				{
					cout << "Error: " << arg << "\nInvalid data content in registet\nThe program will quit\n";
					exit(0);
					/*Error:Invalid data content in registers*/
				}
			}
			else
			{
				cout << "Error: " << arg << "\nInvalid register pair\nThe program will quit\n";
				exit(0);
				/*Error:Invaid register pair*/
			}
		}
		else
		{
			cout << "Error: " << arg << "\nInvalid register content\nThe program will quit\n";
			exit(0);
			/*Error:Invalid register content*/
		}
	}
	else
	{
		cout << "Error: " << arg << "\nInvalid arguments\nThe program will quit\n";
		exit(0);
		/*Error:Invalid Input Argument*/
	}
}