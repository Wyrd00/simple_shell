#include "shell.h"

/**
 * hsh_exit - exits the current process
 * @args: arguments
 * @line: user input
 *
 */
void hsh_exit(char **args, char *line)
{
	unsigned int x = 0;

	free(line);
	while (args[x] != NULL)
	{
		free(args[x]);
		x++;
	}
	free(args);
	free_path(main_path);
	free_path(env);

	exit(0);
}

/**
 * print_env - prints the entire environment array
 *
 */
void print_env(void)
{
	path_t *temp;

	temp = env;
	while (temp)
	{
		write(1, temp->dir, _strlen(temp->dir));
		write(1, "\n", 1);
		temp = temp->next;
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
