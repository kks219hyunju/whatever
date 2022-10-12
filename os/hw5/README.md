# Operating Systems Homework #4 Processes

Print files backwards! With Argument!!! By piped process!!!!

## Table of Contents
- [Dependencies](#dependencies)
- [Program Objective](#program-objective)
- [Program Operation](#program-operation)
- [Arugument](#arugument)
- [Fork](#fork)

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

**The program is optimized to operate with having being piped into the ```cat``` command in Ubuntu**
**The program's reading technique has changed to read the piped file, by the program checking between whather the program is being piped, such that if program sees no -c argument to read the file, it will check ```stdin``` if the file has been piped into the program. Main componet program is checking weather argument -c is passed with filename, if so it will operate as normal normal program with argument, if but it will operate by ```stdin``` file into file operation in the program**

## Arugument

Arugment is being used to run the program. there are three arguments are implimented into this project,
this helps and allows the program to detect what user needs from the program and able to parse an argument
and run the program as user intended to be.

```
./a.out [-r -c -h Argument ...]

cat Filename | ./a.out [-r -c -h Argument ...]
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

## Fork

The fork is program running in the process of the same program.

The assignment we were given with executable file with fork in the program, thus the program calls in the same program within the same program, thus running fork within the fork in the program. and we were able to visualize such by ```strace``` the output of the program execution or ```strace```process child and parent process in ```ps awxsuf```. These two files are also turned in part of the dropbox named ```fork/outfile.txt``` and ```fork/spoon```.
