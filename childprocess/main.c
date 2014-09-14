#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	/* code */	
	int pid;
	if ((pid = fork()) >= 0)
	{
		if (pid == 0)
		{//the child
			printf("%s\n", "child process start");
			sleep(2);
			printf("%s\n", "child process end");
			abort();
		}else if(pid > 0)
		{//the parent
			printf("%s: %d \n", "the child pid" , pid);
			int status;
			int pid = wait(&status);
			printf("the child pid %d exited with status %d \n", pid,status);
		}
	}
	return 0;
}