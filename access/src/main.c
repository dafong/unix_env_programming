#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lapi.h"



int main(int argc,char *argvs[]){
	if (argc < 2)
	{
		fprintf(stderr, "%s\n", "usage: hello.out pathname");
		return 1;
	}
	echo(argvs[1]);

	exit(0);

}