/* 
* @Author: xinleifan
* @Date:   2014-09-09 11:36:25
* @Last Modified by:   xinlei.fan
* @Last Modified time: 2014-09-10 10:56:42
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char path[256] ;
	
	if(NULL != getcwd(path,256)){
		printf("base path: %s\n", path);
	}else{
		fprintf(stderr, "%s\n", "getcwd failed");
		return 1;
	}

	char filepath[256];
	sprintf(filepath,"%s/%s",path,"text.file");

	int fd;
	//ok we create a file first 
	if ((fd = open(filepath,O_WRONLY | O_CREAT )) > 0 )
	{
		char buf[] = "hello test file";
		
		//then we write some byte?
		if(write(fd,buf,strlen(buf)) != strlen(buf)){
			fprintf(stderr, "%s\n", "write error");
			return 1;
		}

		//then close
		if( close(fd) < 0 ){
			fprintf(stderr, "%s\n", "close error");
			return 1;
		}


		//open and seek
		if( (fd = open(filepath,O_RDWR)) < 0 ){
			fprintf(stderr, "%s\n", "reopen error");
		}
        //create hole in file

		if( lseek(fd , 20 ,SEEK_SET) < 0){
			fprintf(stderr, "%s\n", "lseek error");	
		}

		char buf1[] = "text after hole";

		if(write(fd,buf1,strlen(buf1)) != strlen(buf1)){
			fprintf(stderr, "%s\n", "write hole error");
		}
		
		//close
		if( close(fd) < 0 ){
			fprintf(stderr, "%s\n", "close error");
			return 1;
		}
		//atomic operation? you can use pread pwrite or open with O_CREAT option

		//about the sync and fsync
		sync();  //not blocking
		fsync(fd); //blocking till write to the disk
		fdatasync(fd);//same fsync but only effect the data part

		//about fcntl
		int fd_dup = fcntl(fd, F_DUPFD, 0);
		if ( fd_dup < 0 )
		{
			fprintf(stderr, "%s\n", "dup error");
			return 1;
		}

		

		//about ioctl
	}else{
		fprintf(stderr, "%s\n", "open file error");
	}
	
    return 0;
}