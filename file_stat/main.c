#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	
	struct stat buf;
	
	char *info;
	
	for(int i = 0 ; i < argc ; i++){
		printf("%s: ", argv[i]);
		if (lstat(argv[i], &buf) < 0 )
		{
			fprintf(stderr, "lstat error\n");
			continue;
		}

		if (S_ISREG(buf.st_mode))
		{
			info = "regular file";
		}else if (S_ISDIR(buf.st_mode))
		{
			info = "directory file";
		}else if (S_ISCHR(buf.st_mode))
		{
			info = "charactor special";
		}else if (S_ISBLK(buf.st_mode))
		{
			info = "block special";
		}else if (S_ISFIFO(buf.st_mode))
		{
			info = "fifo file";
		}else if (S_ISLNK(buf.st_mode)){
			info = "symbolic link";
		}else if (S_ISSOCK(buf.st_mode))
		{
			info = "socket file";
		}else
			info = "** unknow mode **";

        printf("%s\n", info);
	}
	exit(0);
}