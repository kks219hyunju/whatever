# Operating Systems Homework #6 More Features

Print files, listen on web domain, and logging

## Table of Contents
- [Dependencies](#dependencies)
- [Program Objective](#program-objective)
- [Program Operation](#program-operation)
  - [ncat Operation](#ncat-operation)
  - [Logging](#logging)
- [Arugument](#arugument)

## Dependencies
```stdio.h```, basic I/O operation of C

```stdlib.h```, basic memory allocation, process control

```unistd.h```, access to the POSIX operating system API

```string.h```, use of string in C

```time.h```, use of time in C

## Program Objective

The code is depended on four library files, basic Input/Output, memory allocation,
POSIX system API, string libraries. The program's objective is to read filename from
commandline arguments then print using ```STDOUT:printf()``` new line by reversing the file read from the
arugment. Then strace the process by time delay option and save the ouput to a file.

## Program Operation

The program is run by user inputing an argument while running the program. The user
should run the program by using code like following example. ```./a.out "filename" "delay time"```
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
close the progam

### ncat Operation

ncat is a program that has networking utility able to read and write data across network (concatenate and redirect sockets). 
Using this program, we are able to broadcast the program output result to HTTP protcol. This enables for others to view the
output result via web browesr which supports HTTP protcol.

The program can be run by using command as follows:

```
./a.out -H -r -c [filename] –H | ncat –l [Port number]
```
**note that port number must be above 1024**

After command is ran, then you can access the website by 
```
localhost:[port number]
```
if someone else is accessing it within the network
```
http:[your ip addr]:[port number]
```

### Logging

Logging done by creating a new text file in the desired directory.

Logging will be done by giving desired directory, and it will log the time the program is ran,
the file took to run the output to the HTTP protcol and its PID when the program is ran.

The logging can be ran by using command as follows:
```
./a.out -r -c [filname] -L [log filename]
```

By running ```-L``` parameter, the program will output a log file of your desired log filename.

The output of the log file looks something like this:
```
Weekday Month Day Time Year      filename.PID

Wed Nov  2 21:13:47 2022	Moby_Duck.txt.6281
```

## Arugument

Arugment is being used to run the program. there are three arguments are implimented into this project,
this helps and allows the program to detect what user needs from the program and able to parse an argument
and run the program as user intended to be.

```
./a.out [Argument ...]
```
```
./a.out -r -H -c [Argument file]
```


``` 
-h    Print help and instructions for the program
-r    Read the input file and reverse the line
-c    Give an input file to operate to reverse read the file
-H    HTTP Header option
-L    Enable Logging
```

The ``` -h, help``` argument will only display the help for the program and WILL NOT run the program to reverse the
file provided by the user, if provided. 

The ``` -r, reverse``` argument will only allowed to be operated when ```-c, input file``` is given to reverse the
file. if input file is not given the program will not run.

The ```-H, Header``` arugment will print HTTP Header to the printing. This enables the program to print HTTP header to
the print, and able to cast the program to web browser.

The ```-L, Logging``` arugment will log operation of the program, it will log time it ran, file it took as an argument
and PID when the program is ran.
