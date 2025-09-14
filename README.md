# SysNet1-Project1-Ethan-Tran-Daniel-Eckman

## Purpose

A project that implements a shell with the basic functions to parse user commands, execution, input/output redirections, and background exection

### Features 

- Support command like "cat", "ls", and etc.
- Handles input and output direction with "<" ">"
- Run processes in the background and ends lines with "&"
- Runs debug mode with "myshell -Debug"

#### How To Run This File
- Type "make" in the termial to start the shell
- If wanting to run in debug mode type "./myshell -debug"
- If wanting to run without using debug mode type "./myshell"
- Can exit the program(the shell) by typing "exit" 

#### Some Code To Test The Shell
- Can use the command "ls -1" to look at files 
- Use the command "ls -1 > outputfile.txt" to create a file in the shell 
- Can use the command "./slow &" to run processes in the background and return the pid
- Can use the command "cat" following "<" a file you want to look at in the shell
- If running "./myshell -Debug" to run debuging mode the next push the command "ls -1" it will show the argument ammount and show if a background is running