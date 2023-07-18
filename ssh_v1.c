#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/**
 * main - super simple shell
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
		getline(&lineptr, &n, stdin);
		token = strtok(lineptr, "\n");
		argv[0] = token;
		argv[1] = NULL;
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
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
