#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_user(int);

int main(int argc, char const *argv[])
{
	/* code */
	if(signal(SIGUSR1, sig_user) == SIG_ERR){
		fprintf(stderr, "%s\n", "can't catch SIGUSR1");
	}
	for (;;)
	{
		/* code */
		pause();
	}

	return 0;
}

void sig_user(int signo){
	if (signo == SIGUSR1)
	{
		fprintf(stderr, "%s\n", "received SIGUSR1");
	}

}