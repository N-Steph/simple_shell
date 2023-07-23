#include "main.h"

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
	char *lineptr = NULL, *argv[10];
	size_t n = 0;
	pid_t my_pid;
	int status, i;

	while (1)
	{
		printf("$cisfun$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			break;
		}
		handle_args(&lineptr, argv);
		i = handle_path(argv);
		if (i == -1)
		{
			printf("%s : %d :", __FILE__, errno);
			fflush(stdout);
			perror(argv[0]);
			continue;
		}
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
			if (i == 0)
				free(argv[0]);
		}
	}
	return (0);
}
