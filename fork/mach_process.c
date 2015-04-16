#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	pid = fork();	
	
	if( pid >= 0 ){	
		if( pid == 0 ){
			printf("Children: I am child process\n");
			printf("Children: My parents pid = %d\n",getpid());	
			printf("Children: My pid = %d\n",getppid());
			sleep(120);
			printf("Children: OK bay from child");
			exit(10);
		}
		else{
			printf("Parent: I am parent\n");
			printf("Parent: My pid is %d\n", getpid());
			wait(&status);
			printf("Parent: Child exit code is %d\n", WEXITSTATUS(status));
			printf("Parent: Goodbay from parent\n");
			exit(0);	
		}
		
	}
	else{
		perror("Program: Fork can't start!");
		return 1;
	}
}
