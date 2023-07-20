#ifndef MAIN_H
#define MAIN_H
int _strlen(const char *s);
void print_dir_path(void);
char *_getenv(const char *name);
struct dir_node
{
	char *dir;
	struct dir_node *next;
};
#endif /* MAIN_H */
