#include <stdio.h> //call in library 

int main(int argc, char** argv)
{
	char c = 'L';
	int countH = 0;
	int countT = 0;
	int trash = 0;
	int countB;
	char res;
	while(c != EOF)
	{
		c =getchar();
		if (c == 'H')
		{
			countH++;
			res = longestrun(countH, countT);
		}
		else if ( c == 'T')
		{
			countT++;
			res = longestrun(countH, countT);
		}
	}
	printf("Number of H:");
	printf("%d\n", countH);
	printf("Number of T:");
	printf("%d\n", countT);
	printf("Trash Values:");
	printf("%d\n", trash);
	printf("The longest run was by:");
	printf("%c\n", res);

	return 0;
}


int longestrun (int num1, int num2)
{
	// num1 is countH
	// num2 is countT

	char result;

	if (num1 > num2)
	{
		num2 = 0;
		printf("H: %d\n",num1);
		result = 'H';
	}
	else if(num1 < num2)
	{
		num1 = 0;
		printf("T: %d\n",num2);
		result = 'T';
	}
	else if(num1 == num2)
	{
		printf("xxxH: %d\n",num1);
		printf("xxxT: %d\n",num2);
		result = 'B';
		num1 = 0;
		num2 = 0;
	}
	return result;
}


