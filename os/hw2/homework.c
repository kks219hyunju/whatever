#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char const* filename = argv[1];
	char* time = argv[2];
	ssize_t read;
	char* line = NULL;
	size_t len = 0;
	int tims =0;

	tims = atoi(time);
	FILE *myfile = fopen(filename,"r");
	while ((read = getline(&line, &len, myfile)) != -1)
	{
		printf("%s",line);

	int p = strlen(line)-2;

	for(p; p>=0; p--)
	{
		printf("%c",line[p]);
	}

	printf("\n");
	sleep(tims);
	}

	fclose(myfile);
	return 0;
}
