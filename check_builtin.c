#include "shell.h"
/**
 * check_builtin - checks if builtin has been called
 * @input: input from user
 *
 * Return: returns the proper builtin funciton or NULL on failure
 */
int check_builtin(char **args)
{
	if (_strcmp(args[0], "exit"))
		_exit();
	else if (_strcmp(args[0], "env"))
		print_env();
	else if (_strcmp(args[0], "setenv"))
		setenv();
	else if (_strcmp(args[0], "unsetenv"))
		unsetenv();
	else if (_strcmp(args[0], "cd"))
		_cd(args);
}
