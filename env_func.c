#include "shell.h"
/**
 * _getenv - searches environment list for variable name
 * @name: name of the variable
 *
 * Return: returns a pointer to the corresponding value;
 */
char *_getenv(char *name)
{
	unsigned int x,y;
	char *match, *delim;

	match  = NULL;
	delim = "=";
	x = 0;
	while(environ[x])
	{
		y = 0;
		while(name[y])
		{
			if (name[y]!= environ[x][y])
				break;
			if (name[y + 1] == '\0' && environ[x][y + 1] == '=')
				match = environ[x];
			y++;
		}
		x++;
		if (match)
			break;
	}
	_strtok(match, delim);
	return(_strtok(NULL, delim));
}
