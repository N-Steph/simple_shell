#include "main.h"

/**
 * main - super simple shell
 * @ac: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
	char *lineptr = NULL, *argv[10];
	size_t n = 0;
	int i;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$cisfun$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(lineptr);
			break;
		}
		if (strcmp(lineptr, "\n") == 0)
			continue;
		i = interactive_mode(&lineptr, argv);
		if (i == 2)
			continue;
	}
	return (0);
}

/**
 * interactive_mode - execute shell in interactive mode
 * @lineptr: address of pointer containing buffer of command read by getline()
 * @argv: array of argument
 *
 * Return: -1 (argument does not exist)
 */
int interactive_mode(char **lineptr, char **argv)
{
	pid_t my_pid;
	int status, i;

	handle_args(lineptr, argv);
	built_in(argv, *lineptr);
	i = handle_path(argv);
	if (i == -1)
	{
		print_error_msg(argv);
		return (1);
	}
	my_pid = fork();
	if (my_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			print_error_msg(argv);
			free(*lineptr);
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (i == 0)
			free(argv[0]);
	}
	return (0);
}

/**
 * print_error_msg - prints erro message when wrong command
 * @argv: array of argument
 *
 * Return: nothing
 */
void print_error_msg(char **argv)
{
	printf("%s : %d : ", __FILE__, errno);
	fflush(stdout);
	perror(argv[0]);
}
