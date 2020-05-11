#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
		printf("Requires 3 arguments");
	}
	int status;

	if (fork() == 0)
		execl("/home/joe/dev/60/exec_function/sum.sh", "sum.sh", argv[1], argv[2], argv[3], NULL);
	else
		wait(&status);
    return 0;
}
