#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <time.h> 
 
/* Spawn a child process running a new program. PROGRAM is the name 
   of the program to run; the path will be searched for this program. 
   ARG_LIST is a NULL-terminated list of character strings to be 
   passed as the program's argument list. Returns  the process ID of 
   the spawned process.  */ 

char* getTime()
{
	char * buffer = (char*) malloc(30);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "now: %d:%d\n", tm.tm_min, tm.tm_sec);
    return buffer;
}
 
int spawn (char* program, char** arg_list) 
{
  pid_t child_pid; 
	 
  /* Duplicate this process. */ 
  child_pid = fork (); 
  if (child_pid != 0){ 
    /* This is the parent process. */ 
    // int i = 0;
   //  while(i++<5){
  	// 	sleep (1);
  	// 	printf("child thread woken %d poid %d \n", getpid(),child_pid);
  	// }

    return child_pid; 
  }else {
    /* Now execute PROGRAM, searching for it in the path.  */ 

    int res = execvp (program,  arg_list); 
   //  int i = 0;
   //  while(i++<5){
  	// 	sleep (1);
  	// 	printf("child thread woken %d poid %d \n", getpid(),child_pid);
  	// }
    /* The execvp  function returns only if an error occurs.  */ 
    fprintf (stderr,  "an error occurred in execvp\n"); 
    abort (); 
  }
  printf("this is end of spawn func"); 
} 
 
int main () 
{
  /*  The argument list to pass to the "ls" command.  */ 
   // printf("get time %s", getTime());
  char* arg_list[] = {
    "/Users/varder/Desktop/m2",     /* argv[0], the name of the program.  */ 
    "", 
    "$PWD", 
    NULL      /* The argument list must end with a NULL.  */ 
  }; 
 
  /* Spawn a child process running the "ls" command. Ignore the 
     returned child process ID.  */ 
  int cpid = spawn ("/Users/varder/Desktop/m2", arg_list); 
 
  printf ("got child pid %d", cpid);
  int i = 0;
  while(i++<10){
  	sleep (1);
   // printf("analize m%s", getTime());
  	printf("main thread woken %d  %s \n", getpid(),getTime());
  }
  printf ("done with main program %s \n", getTime()); 
 
  return 0; 
} 