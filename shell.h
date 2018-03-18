#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/* String Helper Functions */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);

/* Shell Loop Functions */
char *read_line(void);

/* Strtok Functions*/

char **tokenize(char *buffer, char *delim);
char *_strtok(char *src, const char *delim);
int word_count(char *s);

#endif /* SIMPLE_SHELL */
