# 8085-Simulator
## Features
1. The simulator is able to take input from a file or on the command line.
2. It contains a debugger.
3. Provides syntax checking and shows the address at which the error is present.
4. User is able to manually input data into registers or memory locations using the R and M functions.

## Functionalities
- R <register\> - update the value of the specifed register.
- M <memory_location\> - update the value at the specified memory location.
- G<address\>. - run the program starting at the specified address.
- A - update the program.
- E - exits simulation.

## Supported commands
The Simulator supports the following commands:
- Load and Store - `MOV , MVI , LXI , LDA , STA , LHLD , SHLD , STAX , XCHG`
- Arithmetic - `ADD , ADI , SUB , INR , DCR , INX , DCX , DAD , SUI`
- Logical - `CMA , CMP`
- Branching - `JMP , JC , JNC , JZ , JNZ`
- One Additional command `SET` which sets data into valid memory locations (ex. `SET 2500,0A`).

## Giving input on console
- The simulator automatically adjusts the program counter according to the instruction used.
- The simulator takes input until EOF is encountered.

## Reading input from a file
The path to the input file can be passed as a command line argument when running the executable.

## Using the debugger
Debugger can be used by passing `--debugger` as a command line argument when running the executable.

The commands for the debugger are: 
1. break or b <line no\>:- It will set break point on given line number.
2. run or r :- It will run the program until it ends or breakpoint is encountered.
3. step or s :- It will run the program one instruction at a time.
4. print or p <register/xmemory_location\>:- It prints the value of register or memory location. for ex p A will print the value of register A. p x2500 will print the value at memory location x2500 (if any).
5. quit or q:- Quit the debugger.
6. help:- Show all the commands of debugger.
