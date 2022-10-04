// 1c Gyungseok Go
// Operating Systems
// Mr. Ethan Gold
// Homework #3
/*
-- arg1 "name of the file"
-- arg2 "delay of each line"

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
				rflag = 1;
				break;
			case 'h':
				hflag = 1;
				break;
			case 'c':
				cvalue = optarg;
				break;
			case '?':
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
		printf("ERROR! PICK ONE ARGUMENT");
	}
	else if(hflag == 1 && rflag = 0)
	{
		printf(" -- arg1 name of the file -- arg2 delay of each line     
		       The following program is to take first argument from 
		       the user and read each line of the file given by the
		       user and print out the line in reverse. The second 
		       argument is the delay between printing of each line. 
		       By using sleep function, the program is able to delay 
		       the printing of each line before outputing next reserved line.")
	}
	else if(rflag == 1 && hflag = 0)
	{
		char const* filename = cvalue; // First argument for file, this is pointer
		char* time = .9; // delay time
		ssize_t read; 
		char* line = NULL; //point of the line is NULL as there cannot be no line in the beginning
		size_t len = 0; // size is not defined until the file is called
		int tims =0; // integer converted delay arugment will be stored here

		tims = atoi(time); // convert the string to integer for delay time
		FILE *myfile = fopen(filename,"r"); // open the file by given by pointer argument
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
	}
	else
	{
		//another long lines of code	
	}
	
	for (index = optind; index < argc; index++)
    		printf ("Non-option argument %s\n", argv[index]);
	return 0;
}
