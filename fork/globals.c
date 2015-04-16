#include "header.h"

int i = 0;

int main()
{
	pid_t pid;
	int status;

	pid = fork();
	
	if( pid >= 0) { 
			sleep(120);
	
			if( pid == 0 ){
				i += 1;
				printf("Child: i = %d, my pid is %d, my parents pid is %d\n", i, getpid(), getppid());	
			}
			else{
				printf("Parent: i = %d, my pid is %d\n", i, getpid());
			}

		}
	else { printf("PID < 0\n");}	
}

