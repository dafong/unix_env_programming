#include <stdlib.h>
#include <stdio.h>

static void onExit1(void);

int main(int argc, char const *argv[])
{

	atexit(onExit1);	

	return 0;
}


void onExit1(void){
	printf("%s\n", "on exit1");
}