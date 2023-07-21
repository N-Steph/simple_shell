#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
extern char **environ;

/**
 * main - super simple shell
 * @ac: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: Always 0
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	pid_t my_pid;
	int status;
	char *token;
	char *argv[2];

	while (1)
	{
		printf("$cisfun$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			break;
		}
		token = strtok(lineptr, "\n");
		argv[0] = token;
		argv[1] = NULL;
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				printf("%s : %d :", __FILE__, errno);
				fflush(stdout);
				perror(argv[0]);
				free(lineptr);
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
