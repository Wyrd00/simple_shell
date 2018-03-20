#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Library Dependencies */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct path
{
	char *dir;
	struct path *next;
} path_t;

/* Global Variables */
extern char **environ;
path_t *main_path;

/* String Helper Functions */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *path_concat(char *s1, char *s2);

/* Shell Loop Functions */
char *read_line(void);
char **tokenize(char *buffer, char *delim);
int execute(char **args);
void loop(void);

/* Tokenize Functions*/
char *_strtok(char *src, const char *delim);
int word_count(char *s);

/* Environment Functions */
char *_getenv(char *name);
path_t *make_path(void);
char *check_path(path_t *head, char *command);

#endif /* SIMPLE_SHELL */
