#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Library Dependencies */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Path Structure */
/**
 * struct path - path node struct
 * @dir: string containing directory
 * @next: pointer to next node.
 */
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
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

/*Memory Helper Functions*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
char *path_concat(char *s1, char *s2);
path_t *_environ(void);

/* Builtin Functions */
int check_builtin(char **args);
void hsh_exit(void);
void print_env(void);
void _cd(char **args);
void *_setenv(*char name, *char value);

#endif /* SIMPLE_SHELL */
