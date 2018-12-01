#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
 

#include <time.h> 
 char* getTime()
{
  char * buffer = (char*) malloc(30);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "now: %d:%d\n", tm.tm_min, tm.tm_sec);
    return buffer;
}
 
int main () 
{
  /*  The argument list to pass to the "ls" command.  */ 
  char* arg_list[] = {
    "m2",     /* argv[0], the name of the program.  */ 
    "-l", 
    "/", 
    NULL      /* The argument list must end with a NULL.  */ 
  }; 
 
 
  printf ("I new child %d\n", getpid());
  int i = 0;
  while(i++<8){
  	sleep (1);
  	printf("child thread woken %d my parent is%d %s\n", getpid(), getppid(),getTime());
  }
 
  return 0; 
} 