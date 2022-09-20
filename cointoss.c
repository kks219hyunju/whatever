#include <stdio.h> //call in library 

int main(int argc, char** argv) //main function
{
	char c = 'L'; // declare char c
	int countH = 0; // declear int variable countH
	int countT = 0; // delcear int variable countT
	int totalH = 0; // declear int varialbe totalH
	int totalT = 0; // declear int variable totalT
	char result; // declear char varaibla result
	int biggestCount=0; //declear int variable biggestCount
	while((c=getchar()) != EOF) //while c is geting letters from piped file, and End of Letter
	{
		if (c == 'H') //check if ltter is H
		{
			countH++; // if so, add one
			countT = 0; // make sure count T is zero
			if(countH > totalH) //if countH is bigger than previously saved totalH, overwrite it
			{
				totalH = countH;
			}
		}
		else if ( c == 'T') // check if letter is T
		{
			countT++; //if so , add one to countT
			countH = 0; // make sure count H is zero
			if(countT > totalT) // if countT is bigger than previously saved totalT, overwrite it
			{
				totalT = countT;
			}
		}



		if (totalH > totalT) //check if totalH is bigger than totalT
		{
			result = 'H'; // if so, the winner is H
			biggestCount = totalH; // thus biggest count is Heads
		}
		else if (totalT > totalH) //check if the totalT is bigger than totalH
		{
			result = 'T'; //if so, the winner is Tails
			biggestCount = totalT; //thus biggest count is tails
		}
		else if (totalT == totalH) //check if both Tail counts and Head counts are the same
		{
			result = 'B'; //if they are both same counts, both are winner
			biggestCount = totalT;// thus biggest count is both
		}
	}
	printf("longest consecutive count of %d, with letter %c\n", biggestCount, result);
	//return longest count for the count, and which letter had longest consecutive count

	return 0; //successful operation of the program.
}
