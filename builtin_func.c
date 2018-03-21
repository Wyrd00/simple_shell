#include "shell.h"

/**
 * _exit - exits the current process
 *
 */
void _exit(void)
{
	exit(0);
}

/**
 * print_env - prints the entire environment array
 *
 */
void print_env(void)
{
	unsigned int x;

	x = 0;
	while (environ[x])
	{
		write(1, environ[x], _strlen(environ[x]));
		write(1, "\n", 1);
		x++;
	}
}

/**
 * _cd - changes directory
 * @args: command line arguments
 *
 */

void _cd(char **args)
{
	printf("This would change directory to: %s", args[1]);
}
