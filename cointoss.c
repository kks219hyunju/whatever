#include <stdio.h> //call in library 

int main(int argc, char** argv)
{
	char c = 'L';
	int countH = 0;
	int countT = 0;
	int totalH = 0;
	int totalT = 0;
	int trash = 0;
	char result;
	int biggestCount=0;
	int otrash;
	while((c=getchar()) != EOF)
	{
		if (c == 'H')
		{
			countH++;
			countT = 0;
			if(countH > totalH)
			{
				totalH = countH;
			}
		}
		else if ( c == 'T')
		{
			countT++;
			countH = 0;
			if(countT > totalT)
			{
				totalT = countT;
			}
		}



		if (totalH > totalT)
		{
			result = 'H';
			biggestCount = totalH;
		}
		else if (totalT > totalH)
		{
			result = 'T';
			biggestCount = totalT;
		}
		else if (totalT == totalH)
		{
			result = 'B';
			biggestCount = totalT;
		}
	}
	printf("longest consecutive count of %d, with letter %c\n", biggestCount, result);

	return 0;
}
