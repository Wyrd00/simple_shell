#include "shell.h"
/**
 * _environ - 
 * 
 */
path_t *_environ(void)
{
	path_t *head;
	path_t *vagabond;
	int x = 0;

	head = malloc(sizeof(path_t));
	if (!head)
		return (NULL);
	vagabond = head;
	while (environ[x])
	{
		vagabond->dir = environ[x];
		if (environ[x] != NULL)
		{
			vagabond->next = malloc(sizeof(path_t));
			vagabond = vagabond->next;

		}
		else
			vagabond->next = NULL;
		x++;
	}
	return (head);
}
