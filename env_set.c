#include "shell.h"

/**
 * locate_env - find env associated with name
 * @env: environ
 * @name: name of string to be found
 * Return: 0 if success, -1 if fail
 */

int locate_env(char *name)
{
	path_t *temp;
	int x = 0; 
	int y = 0;

	temp = env;
	while (temp)
	{
		y = 0;
		while (name[y] == temp->dir[y])
		{
			y++;
			if (name[y + 1] == '\0' && (temp->dir)[y + 1] == '=')
				return (x);
		}
		x++;
		temp = temp->next;
		if (temp == NULL)
			return (-1);
	}
	return (x);
}


/**
 * _setenv - create a new environment variable
 * @name: key
 * @value: value
 * Return: 0 if success, -1 if fail
 */
void _setenv(char *name, char *value)
{
	path_t *holder, *temp, *new;
	int curr_i = 0;
	int counter = 0;

	/*returns a pointer to the value of name*/
	curr_i = locate_env(name);

	new = malloc(sizeof(path_t));
	if (!new)
	{
		perror("99 Problems and you are one of them\n");
	}

	holder = env;
	temp = env;
	if (curr_i >= 0)
	{
		while (counter != (curr_i - 1)) /*stop one node prior to curr_value*/
		{
			temp = temp->next;
			holder = holder->next;
			counter++;
		}
		holder = holder->next; /*pointing to node to be deleted*/
		new->dir = _strcat(_strcat(name, "="), value);
		new->next = temp->next->next;
		temp->next = new;
		free(holder);
	}
	else /*add the new environ at the end*/
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new->dir = _strcat(_strcat(name, "="), value);
		temp->next = new;
		new->next = NULL;
	}
}
/**
 * _unsetenv - delete an environment variable
 * @name: key to be deleted
 *
 * Return: 0 if success, -1 if fail
 */

/*int *_unsetenv(char *name)
{
	char *remove;

	if (!remove)
	{
		perror("Nothing to remove homie\n")
	}
	return (0);
}*/
