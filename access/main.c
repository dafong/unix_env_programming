#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argvs[]){
	if (argc < 2)
	{
		fprintf(stderr, "%s\n", "usage: hello.out pathname");
		return 1;
	}

	if (access(argvs[1],R_OK) <  0)
	{
		fprintf(stderr, "access error for %s\n", argvs[1]);

	}else{
		printf("%s\n", "access OK");
	}

	exit(0);

}