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
    fork(); // check and use the return value new code block?
    sleep(2);// print something useful here
  }

  printf("never is the end is "); // print something useful here
  return 0;
  
} // end main()
