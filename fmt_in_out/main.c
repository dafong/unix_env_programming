#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int dump(const char *fmt,...);

int main(int argc, char const *argv[])
{
	printf("%s %s\n", "test out put" ,"ah");
	printf("%-20s %s\n", "test out put","ah");

	dump("%s %10d\n","i am the string",23);


	return 0;
}

int dump(const char *fmt,...){
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
	return 0;
}