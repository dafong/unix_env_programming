#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("Hello World from cmake!\n");
	printf("The process id is: %ld \n",(long)getpid());
	return 0;
}