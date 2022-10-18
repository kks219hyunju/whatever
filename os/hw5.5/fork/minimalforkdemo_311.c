/*****************************************
 * From Silbershatz, Chapter 3 problems (corrected):
 * 3.11 Including the initial parent process, how many processes
 * are created by the program below?
 * Add debugging statements to explore what it does.
 * Try using getpid(), fprintf(), and the return value from fork().
 *****************************************/
#include <stdio.h>
#include <unistd.h>


int main() {
  
  int i;

  for (i = 0; i < 4; i++) {
    printf("%d, this is Pid: %d \n", i, getpid());// print something useful here
    printf("%d, this is PPid: %d \n",i, getppid());
    fork(); // check and use the return value new code block?
    sleep(20);// print something useful here

    switch(i){
	case 1:
	printf("i'm the first child \n");
	case 2:
	printf("i'm the second child \n");
	case 3:
	printf("i'm the third child \n");
	case 4:
	printf("i'm the fourth child \n");
	}
  }

  printf("never is the end is "); // print something useful here
  return 0;
  
} // end main()
