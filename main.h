#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
extern char **environ;
int _strlen(const char *s);
void print_dir_path(void);
char *_getenv(const char *name);
struct dir_node
{
	char *dir;
	struct dir_node *next;
};
void handle_args(char **lineptr, char **agrs);
int handle_path(char **agrs, int *output_num);
struct dir_node *linked_list_dir_path(void);
void free_list(struct dir_node *head);
int built_in(char **args, char *lineptr);
void _printenv(void);
void print_error_msg(char **argv, int *output_num);
void interactive_mode(char **lineptr, char **argv, int *output_num);
#endif /* MAIN_H */
