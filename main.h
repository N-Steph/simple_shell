#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
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
#endif /* MAIN_H */
