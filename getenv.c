#include "shell.h"
/**
 * _getenv - searches environment list for variable name
 * @name: name of the variable
 *
 * Return: returns a pointer to the corresponding value;
 */
char *_getenv(char *name)
{
	unsigned int x, y;
	char *match, *delim, *token;
	path_t *check_environ;

	match = NULL;
	delim = "=";
	x = 0;

	check_environ = _environ();
	while (check_environ)
	{
		y = 0;
		while (name[y])
		{
			if (name[y] != check_environ->dir[y])
			{
				break;
			}
			if (name[y + 1] == '\0' && check_environ->dir[y + 1] == '=')
			{
				match = check_environ->dir;
			}
			y++;
		}
		check_environ = check_environ->next;
		if (match)
			break;
	}
	token = _strtok(match, delim);
	/*removed _strtok(NULL,delim)*/
	return (token);
}
