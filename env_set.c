#include "shell.h"

/**
 * locate_env - find env associated with name
 * @env: environ
 * @name: name of string to be found
 * Return: 0 if success, -1 if fail
 */

int locate_env(path_t *env, char *name)
{
	int x = 0; 
	int y = 0;

	while (env)
	{
		while (name[y] == (env->dir)[y])
		{
			y++;
		}
		if (name[y] == '\0')
		{
			break;
		}
		env = env->next;
		x++;
	}
	if (env == NULL)
		return (-1);
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
	path_t *head;
	path_t *temp, *new;
	int curr_i = 0;
	int counter = 0;

	head = env;

	/*returns a pointer to the value of name*/
	curr_i = locate_env(env, name);

	new = malloc(sizeof(path_t));
	if (!new)
	{
		perror("99 Problems and you are one of them\n");
	}
	
	env = head;
	temp = head;
	if (curr_i != -1)
	{
		while (counter != (curr_i - 1)) /*stop one node prior to curr_value*/
		{
			temp = temp->next;
			env = env->next;
			counter++;
		}
		env = env->next;
		new->dir = _strcat(_strcat(name, "="), value);
		new->next = temp->next->next;
		temp->next = new;
		free(env);
	}
	else /*add the new environ at the end*/
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new->dir = _strcat(_strcat(name, "="), value);
		temp->next = new;
		new = NULL;
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
