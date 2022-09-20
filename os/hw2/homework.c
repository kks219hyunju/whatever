#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char const* filename = argv[1];
	char* time = argv[2];
	ssize_t read;
	char* line = NULL;
	size_t len = 0;
	int tims =0;
	int p = 0;

	tims = atoi(time);
	FILE *myfile = fopen(filename,"r");
	while ((read = getline(&line, &len, myfile)) != -1)
	{
		printf("%s",line);
		sleep(tims);
	}

	p = strlin(line)-1;
	if(p; p<=0; p--)
	{
		printf("%c",line[p]);
	}

	fclose(myfile);
	return 0;
}
