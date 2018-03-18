#include "shell.h"

char *read_line(void)
{
	int length;
	char *line = NULL;
	ssize_t n = 0;

	write(STDOUT_FILENO, "$)> ", 4);
	getline(&line, &n, stdin);
	length = _strlen(line);
	line[length - 1] = '\0';
	return (line);
}
