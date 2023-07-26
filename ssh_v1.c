#include "main.h"

/**
 * main - super simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
	char *lineptr = NULL, *argv[10];
	size_t n = 0;
	int output_num = 1;

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
		{
			++output_num;
			continue;
		}
		interactive_mode(&lineptr, argv, &output_num);
		++output_num;
	}
	return (0);
}

/**
 * interactive_mode - execute shell in interactive mode
 * @lineptr: address of pointer containing buffer of command read by getline()
 * @argv: array of argument
 * @output_num: pointer to variable storing the number of command executed
 *
 * Return: nothing
 */
void interactive_mode(char **lineptr, char **argv, int *output_num)
{
	pid_t my_pid;
	int status, i;
	char *in_command;

	in_command = argv[0];
	handle_args(lineptr, argv);
	i = built_in(argv, *lineptr);
	if (i == -1)
		return;
	i = handle_path(argv, output_num);
	if (i == -1)
	{
		return;
	}
	my_pid = fork();
	if (my_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			print_error_msg(in_command, output_num);
			free(*lineptr);
			return;
		}
	}
	else
	{
		wait(&status);
		if (i == 0)
			free(argv[0]);
	}
}

/**
 * print_error_msg - prints erro message when wrong command
 * @in_command: pointer to command passed through terminal
 * @output_num: pointer to variable storing the number of command executed
 *
 * Return: nothing
 */
void print_error_msg(char *in_command, int *output_num)
{
	printf("hsh : %d : ", *output_num);
	fflush(stdout);
	perror(in_command);
}
