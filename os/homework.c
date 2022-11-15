// 1c Gyungseok Go
// Operating Systems
// Mr. Ethan Gold
// Homework #6
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

int readback(char* fileCall,int revalue)
{
	char const* filename = fileCall; // First argument for file, this is pointer
	FILE *myfile = NULL;
	ssize_t read; 
	char* line = NULL; //point of the line is NULL as there cannot be no line in the beginning
	size_t len = 0; // size is not defined until the file is called
	int tims = 0; // integer converted delay arugment will be stored here

	if(fileCall == "hello")
	{
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			printf("%s",line); //print line as it reads

			int p = strlen(line)-2; //remove empty lines between the reserved line, detect number of characters
			
			if(revalue){
			for(; p>=0; p--) //printing words in reverse happens here
			{
				// as the for loop counts down, it will print out each letter from the end of the line
				printf("%c",line[p]); 
			}}

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

			if(revalue){
			for(; p>=0; p--) //printing words in reverse happens here
			{
				// as the for loop counts down, it will print out each letter from the end of the line
				printf("%c",line[p]); 
			}}

			printf("\n");
			sleep(tims); //sleep for given time by the user
		}

		fclose(myfile); //close file
		return 0;
	}
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
	int fflag = 0;
	char *lvalue = NULL;
	char *cvalue = NULL;
	int index;
	int opt;
	
	opterr = 0;
	
	while((opt= getopt(argc,argv,"L:rHhf")) != -1)
		switch(opt)
		{
			case 'r':
				// check for r argument
				rflag = 1;
				break;
			case 'f':
				fflag = 1;
				break;
			case 'h':
				// check for h argument
				hflag = 1;
				break;
			case 'H':
				flagH = 1;
				break;
			case 'L':
				flagL = 1;
				lvalue = optarg;
				break;
			default:
				return 1;
		}

	if(flagH)
	{
                printf("HTTP/1.0 200\n");
                printf("Content-type: text/plain\n\n");
		fflush(stdin);
        }
	if(flagL)
	{
		writeLog(lvalue,argv[optind]);
	}
	if(hflag && rflag)
        {
                printf("ERROR! PICK ONE ARGUMENT\n"); // if both h>
		return 1;
        }
        else if(hflag)
        {
		printf("USAGE: ./a.out/ -c name of the file -r -L logfilename\n");
                // help functoin
        }

	if(optind < argc)
	{
		cvalue = argv[optind];
		do
		{
		readback(argv[optind],rflag);
		}
		while(++optind < argc);
	}
	else if(stdin != NULL)
	{
	readback("hello",rflag);
	}

        for (index = optind; index < argc; index++)
                printf ("Non-option argument %s\n", argv[index]); //if no argument is selected
	return 0;
}
