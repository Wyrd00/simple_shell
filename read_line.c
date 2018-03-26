#include "shell.h"
/**
 * read_line - gets command line from user
 *
 * Return: returns the user input from the command line
 */
char *read_line(void)
{
	char *line = NULL;
	unsigned int len = 0;
	size_t n = 0;

	write (1, "$ ", 2);
	if (getline(&line, &n, stdin) <= 0)
	{
		exit(0);
	}
	len = _strlen(line);
	line[len - 1] = '\0';
	return (line);
}
