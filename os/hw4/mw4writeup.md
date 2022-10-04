# Operating Systems Homework #3 Processes

Print files backwards! With Argument!!!

## Table of Contents
- [Dependencies](#dependencies)
- [Program Objective](#program-objective)
- [Program Operation](#program-operation)
- [Arugument](#arugument)

## Dependencies
```stdio.h```, basic I/O operation of C

```stdlib.h```, basic memory allocation, process control

```unistd.h```, access to the POSIX operating system API

```string.h```, use of string in C

## Program Objective

The code is depended on four library files, basic Input/Output, memory allocation,
POSIX system API, string libraries. The program's objective is to read filename from
commandline arguments then print using ```STDOUT:printf()``` new line by reversing the file read from the
arugment. Then strace the process by time delay option and save the ouput to a file.

## Program Operation

The program is run by user inputing an argument while running the program. The user
should run the program by using code like following example. ```./main.out "filename" "delay time"```
Once argument is inputed to the program, it will read the size of the file, and read
the time delay in string, it will convert into integer by ```atoi``` function.

The program will open the file given to them, and use ```getline``` function to 
receive the text line by line, and as it reads the line, it will also print the
line backwards by using ```strlin(line)-2```, this allows print the current
line in the text file to print in reverse. Once the reversed line is printed,
program will ```sleep``` the amount of time given by the user in the second
argument until do the next operation.

The program will repeat this operation until there is no more line to be printed
from the file inserted into the argument by the user. Once this process is completed,
it will close the inputted file via ```fclose``` and ```return 0``` to successfully
close the progam.

## Arugument

Arugment is being used to run the program. there are three arguments are implimented into this project,
this helps and allows the program to detect what user needs from the program and able to parse an argument
and run the program as user intended to be.

```
./main.out [Argument ...]
```


``` 
-h    Print help and instructions for the program
-r    Read the input file and reverse the line
-c    Give an input file to operate to reverse read the file
```

The ``` -h, help``` argument will only display the help for the program and WILL NOT run the program to reverse the
file provided by the user, if provided. 

The ``` -r, reverse``` argument will only allowed to be operated when ```-c, input file``` is given to reverse the
file. if input file is not given the program will not run.
