#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 6;

char buf[] = "a write to std out \n" ;

int main(int argc,char *argv[] )
{
	int var;
	int pid;
	var = 100;
	
	if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf) - 1)
	{
		/* code */
	    fprintf(stderr, "write std out error\n");
	}

	printf("before fork\n");
	if ( (pid = fork()) < 0 )
	{
		fprintf(stderr, "create child proccess failed\n" );
	}

	if ( pid == 0)
	{//in child
		/* code */
		var++;
		global++;
	}else{
		// in parent
		sleep(2);
	}
	
	printf("pid = %ld , var = %d, gloval = %d \n", (long)getpid() , var , global);
	exit(0);
}