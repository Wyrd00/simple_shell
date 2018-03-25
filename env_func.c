#include "shell.h"
/**
 * _getenv - searches environment list for variable name
 * @name: name of the variable
 *
 * Return: returns a pointer to the corresponding value;
 */
char *_getenv(char *name)
{
	unsigned int y;
	char *match, *delim, *copy;

	match = NULL;
	delim = "=";
	while (env)
	{
		y = 0;
		while (name[y])
		{
			if (name[y] != env->dir[y])
				break;
			if (name[y + 1] == '\0' && env->dir[y + 1] == '=')
				match = env->dir;
			y++;
		}
		if (match)
			break;
		env = env->next;
	}
	copy = _strdup(match);
	_strtok(copy, delim);
	match = _strtok(NULL, delim);
//	free(copy);
	return (match);
}
