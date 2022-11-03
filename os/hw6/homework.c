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
	ssize_t read; 
	char* line = NULL; //point of the line is NULL as there cannot be no line in the beginning
	size_t len = 0; // size is not defined until the file is called
	int tims = 0; // integer converted delay arugment will be stored here

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


char writeLog(char * lv, char * cv)
{
	if(strchr(lv,'-') != NULL)
	{
		printf("INVALID DIRECTORY\n");
		return -1;
	}
	FILE * logf = NULL; //create file variable logf
	logf = fopen(lv,"a+");  // open file with name lv

	time_t timestamp;
	char timebuff[128];

	time(&timestamp);	//timestamp creation
	ctime_r(&timestamp,timebuff);	//ctime is giving timestamp time
	
	//Writing text onto given timestamp name
	timebuff[strcspn(timebuff, "\n")] = 0;
	fprintf(logf, "%s", timebuff);
	fprintf(logf, "\t");
	fprintf(logf, "%s", cv);
	fprintf(logf,".");
	fprintf(logf, "%d", getpid());
	fprintf(logf, "\n");
	fclose(logf);
}



int main(int argc, char *argv[]) //delcaring input arguments in main function
{
	int hflag = 0;
	int rflag = 0;
	int flagH = 0;
	int flagL = 0;
	char *lvalue = NULL;
	char *cvalue = NULL;
	int index;
	int opt;
	
	opterr = 0;
	
	while((opt= getopt(argc,argv,"L:rHhc:")) != -1)
		switch(opt)
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
			case 'H':
				flagH = 1;
				break;
			case 'L':
				flagL = 1;
				lvalue = optarg;
				break;
			case '?':
				return 1;
			default:
				abort();
		}

	if(flagH == 1)
	{
                printf("HTTP/1.0 451\n");
                printf("Content-type: text/plain\n\n");
		fflush(stdin);
        }
	if(flagL == 1)
	{
		writeLog(lvalue,cvalue);
	}
	if(hflag == 1 && rflag == 1)
        {
                printf("ERROR! PICK ONE ARGUMENT\n"); // if both h>
        }
        else if(hflag == 1 && rflag == 0)
        {
		printf("USAGE: .main.out/ -c name of the file -r delay of each line or cat filename.txt | ./main.out -r -c \n");
                // help functoin
        }
        else if(rflag == 1 && hflag == 0 && cvalue == NULL)
        {
                printf("INPUT A FILE TO BE READ \n");
        }
        else if(rflag == 1 && hflag == 0)
        {
                readback(cvalue); //call in readback function
        }
        else
        {
                printf("FAILED!\n");    //if nothing is called, its failed
        }

        for (index = optind; index < argc; index++)
                printf ("Non-option argument %s\n", argv[index]); //if no argument is selected
	return 0;
}
