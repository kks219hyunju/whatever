// 1c Gyungseok Go
// Operating Systems
// Mr. Ethan Gold
// Homework #3
/*
-h is help document
-r is to read the file in reverse like hw2
-c is needed for the file document
The following program is to take first argument from the user
and read each line of the file given by the user and
print out the line in reverse. The second argument is
the delay between printing of each line. By using "sleep"
function, the program is able to delay the printing of each line
before outputing next reserved line.
*/


//Calling in all required libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>



int readback(char* fileCall)
{
	char const* filename = fileCall; // First argument for file, this is pointer
	if(!fileCall)
	{
		fileCall = stdin;
	}
	else
	{
		FILE *myfile = fopen(filename,"r"); // open the file by given by pointer argument
	}
	
	ssize_t read; 
	char* line = NULL; //point of the line is NULL as there cannot be no line in the beginning
	size_t len = 0; // size is not defined until the file is called
	int tims = 1; // integer converted delay arugment will be stored here

	while ((read = getline(&line, &len, myfile)) != -1)
	{
		printf("%s",line); //print line as it reads

	int p = strlen(line)-2; //remove empty lines between the reserved line, detect number of characters

	for(p; p>=0; p--) //printing words in reverse happens here
	{
		// as the for loop counts down, it will print out each letter from the end of the line
		printf("%c",line[p]); 
	}

	printf("\n");
	sleep(tims); //sleep for given time by the user
	}

	fclose(myfile); //close file
	return 0;
}



int main(int argc, char *argv[]) //delcaring input arguments in main function
{
	int hflag = 0;
	int rflag = 0;
	char *cvalue = NULL;
	int index;
	int c;
	
	opterr = 0;
  
	
	while((c= getopt(argc,argv,"hrc:")) != -1)
		switch(c)
		{
			case 'r':
				// check for r argument
				rflag = 1;
				break;
			case 'h':
				// check for h argument
				hflag = 1;
				break;
			case 'c':
				// check for c argument for input file
				cvalue = optarg;
				break;
			case '?':
				// if there is no c input file, then request one
				if (optopt == 'c')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
					(stderr,"Unknown option character `\\x%x'.\n", optopt);
				return 1;
			default:
				abort();
		}
	
	
	if(hflag == 1 && rflag == 1)
	{
		printf("ERROR! PICK ONE ARGUMENT\n"); // if both help and readback is called give an error
	}
	else if(hflag == 1 && rflag == 0)
	{
		printf("-- arg1 name of the file -- arg2 delay of each line     The following program is to take first argument from the user and read each line of the file given by the user and print out the line in reverse. The second argument is the delay between printing of each line. By using sleep function, the program is able to delay the printing of each line before outputing next reserved line. \n");
		// help functoin
	}
	else if(rflag == 1 && hflag == 0 && cvalue == NULL)
	{
		readback();
	}
	else if(rflag == 1 && hflag == 0)
	{
		readback(cvalue); //call in readback function
	}
	else
	{
		printf("FAILED!\n");	//if nothing is called, its failed
	}
	
	for (index = optind; index < argc; index++)
    		printf ("Non-option argument %s\n", argv[index]); //if no argument is selected
	return 0;
}
