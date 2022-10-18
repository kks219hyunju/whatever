// 1c Gyungseok Go
// Operating Systems
// Mr. Ethan Gold
// Homework #5
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
#include <sys/wait.h>


int readback(char* fileCall)
{
	char const* filename = fileCall; // First argument for file, this is pointer
	FILE *myfile = NULL;
	ssize_t read; 
	char* line = NULL; //point of the line is NULL as there cannot be no line in the beginning
	size_t len = 0; // size is not defined until the file is called
	int tims = 1; // integer converted delay arugment will be stored here

	if(fileCall == "hello")
	{
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			printf("%s",line); //print line as it reads

			int p = strlen(line)-2; //remove empty lines between the reserved line, detect number of characters

			for(; p>=0; p--) //printing words in reverse happens here
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
	else
	{
		FILE *myfile = fopen(filename,"r"); // open the file by given by pointer argument
		while ((read = getline(&line, &len, myfile)) != -1)
		{
			printf("%s",line); //print line as it reads

			int p = strlen(line)-2; //remove empty lines between the reserved line, detect number of characters

			for(; p>=0; p--) //printing words in reverse happens here
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
}

void forkDothings(char* theThing)
{

  if (fork() == 0)
    {
      readback(theThing);
    }
  else
    {
      
    }
}



int main(int argc, char *argv[]) //delcaring input arguments in main function
{
	int hflag = 0;
	int rflag = 0;
	char *cvalue = NULL;
	int index;
	int c;
	int returnStatus;
	int childPid;
	
	
	opterr = 0;

	
	while((c= getopt(argc,argv,"hrc:")) != -1)
	{
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
			default:
				// if there is no c input file, then request one
				if (c != 'h' || c != 'r')
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
					(stderr,"Unknown option character `\\x%x'.\n", optopt);
				return 1;
		}
			
		if(hflag == 1 && rflag == 1)
		{
		    printf("ERROR! PICK ONE ARGUMENT\n"); // if both help and readback is called give an error
		}
		else if(hflag == 1 && rflag == 0)
		{
		  printf("USAGE: .main.out/ -c name of the file -r delay of each line or cat filename.txt | ./main.out -r -c \n");
		  // help functoin
		}
		else if(rflag == 1 && hflag == 0 && optind < argc)
	        {
		  do
		    {
		      forkDothings(argv[optind]);
		    }
		  while(++optind < argc);
		}
		else if(rflag == 1 && hflag == 0 && cvalue == NULL)
		{
		  readback("hello");
		}
		else
		{
		  printf("FAILED!\n");	//if nothing is called, its failed
		}
	}
	for (index = optind; index < argc; index++)
    		printf ("Non-option argument %s\n", argv[index]); //if no argument is selected.

	while(wait(NULL)>0);
	return 0;
	
 }
