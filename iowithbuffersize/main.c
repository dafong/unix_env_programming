#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE   4096

int main(void)
{
	clock_t start;
	start = clock();

	int n;
	char buf[BUFFER_SIZE];
	while ( (n = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0 ){
		if (write(STDOUT_FILENO, buf, n) != n )
		{
			fprintf(stderr, "write error\n");
		}
	}
    if ( n < 0 )
    {
    	fprintf(stderr,"read error\n");
    }

    clock_t end;
	end = clock();
   
    fprintf(stderr,"cost %ld clock\n", ((long)end - (long)start));
    exit(0);
}