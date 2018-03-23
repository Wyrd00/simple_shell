#include "shell.h"
/**
 * _setenv - create a new environment variable (!!NEED TO BETTY CHECK!!)
 * @name: key
 * @value: value
 * Return: 0 if success, -1 if fail
 */
void *_setenv(char *name, char *value)
{
	path_t *head;
	path_t *temp;
	path_t *new;
	char *curr_value, *concated_str;

	head = _environ();
	if (!head)
		return (NULL);

	/*returns a pointer to the value of name*/
	curr_value = _getenv(name);
	printf("curr_value = %s\n", curr_value);

	new = malloc(sizeof(path_t));
	if (!new)
	{
		//free(head);
		//free(curr_value);
		perror("99 Problems and you are one of them\n");
	}
	concated_str = _strcat(_strcat(name, "="), value);
	temp = head;
	if (curr_value)
	{
		while (temp->next->dir != curr_value)/*stop one node prior to curr_value*/
		{
			temp = temp->next;
		}
		new->dir = _strcat(_strcat(name, "="), value);
		new->next = temp->next->next;
		temp->next = new;
		temp = temp->next;
//		free(temp);
		temp = head;
		while (temp)
		{
			printf("environ: %s\n", temp->dir);
			temp = temp->next;
		}
	}
	else /*add the new environ at the end*/
	{
		while (temp->next != NULL)
		{
			printf("environ is %s\n", temp->dir);
			temp = temp->next;
		}
		new->dir = _strcat(_strcat(name, "="), value);
		temp->next = new;
//		printf("%s\n", environ[i]);
		new = NULL;
	}
}

/**
 * _unsetenv - delete an environment variable
 * @name: key to be deleted
 *
 * Return: 0 if success, -1 if fail
 */

//int *_unsetenv(char *name)
//{
//	char *remove;

//	if (!remove)
//	{
//		perror("Nothing to remove homie\n")
//	}
//	return (0);
//}
