#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc , char *argv[]){
	puts("ready to dump txt\n");
	FILE *file;
	if ( (file = fopen("yia.txt", "ab")) != NULL ){

		char str[256] ;
		fgets(str,256,stdin);
		for (int i = 0; i < 5; ++i)
		{

			fputs(str, file);
			puts(str);
		}
		fflush(file);
		puts("write over\n");
	}else{
		fprintf(stderr, "%s\n", "create yia.txt failed");
	}

	exit(0);
}