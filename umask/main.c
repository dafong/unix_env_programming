#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char *argv[]){

	umask(0);
	if(creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ) < 0 ){
		fprintf(stderr, "%s\n", "create failed");
		exit(1);
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (creat("bar" , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH  ) < 0 )
	{
		fprintf(stderr, "%s\n", "create failed");
		exit(1);
	}

	exit(0);
}