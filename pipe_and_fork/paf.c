#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum PIPE_TYPE {READ, WRITE};

const size_t BUFFER_SIZE = 1000;

int main()
{
	char message[] = "I am the child. This is Spring 2020 (Actually, I think I'm the parent, but the assignment says to say I'm the child and I do what I'm told.)";
	ssize_t numbytes;
	char buf[BUFFER_SIZE];
	int fd[2];
	int status;

	status = pipe(fd);
	if (status == -1)
		exit(-1);

	switch (fork()) {
	case -1:
		// Error ocurred
		exit(-1);
	case 0:
		// Child
		close(fd[READ]);
		write(fd[WRITE], message, strlen(message));
		close(fd[WRITE]);
		exit(EXIT_SUCCESS);
	default:
		// Parent
		wait(NULL);
		close(fd[WRITE]);
		numbytes = read(fd[0], buf, BUFFER_SIZE);
		printf("%s\n", buf);
		close(fd[READ]);
		exit(EXIT_SUCCESS);
	}

	return 0;
}
