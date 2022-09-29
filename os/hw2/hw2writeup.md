# Operating Systems Homework #2 Processes

Print files backwards!

## Table of Contents
[Dependencies](Dependencies)
[Program Objective](Program-Objective)
[Program Operation](Program-Operation)

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
should run the program by using code like following example. ```./output.a "filename" "delay time"```
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
