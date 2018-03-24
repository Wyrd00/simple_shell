#include "shell.h"
/**
 * check_builtin - checks if builtin has been called
 * @args: argv array
 *
 * Return: returns the proper builtin funciton or NULL on failure
 */
int check_builtin(char **args, char *line)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		hsh_exit(args, line);
		return (0);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		printf("This does setenv\n");
		return (0);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		printf("This does unsetenv\n");
		return (0);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		_cd(args);
		return (0);
	}
	return (1);
}
