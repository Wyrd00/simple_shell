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

/* String Helper Functions */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);

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

#endif /* SIMPLE_SHELL */
