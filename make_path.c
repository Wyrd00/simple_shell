#include "shell.h"

/**
 * make_path - make path
 *
 * Return: returns the head of the path;
 */

path_t *make_path(void)
{
	path_t *head;
	path_t *temp;
	char *path_name, *token;

	temp = malloc(sizeof(path_t));

	if (!temp)
		return (NULL);

	path_name = _strdup(_getenv("PATH"));

	if (!path_name)
		return (NULL);

	token = _strtok(path_name, ":");
	head = temp;
	while (token)
	{
		temp->dir = token;
		token = _strtok(NULL, ":");
		if (token != NULL)
		{
			temp->next = malloc(sizeof(path_t));
			temp = temp->next;
		}
		else
			temp->next = NULL;
	}
	return (head);
}
