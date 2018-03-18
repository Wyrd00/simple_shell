#include "shell.h"

/**
 * tokenize - tokenizes buffer with delim
 * @buffer: buffer to tokenize
 * @delim: delim
 * Return: pointer to arr of pointers to tokens
 */

char **tokenize(char *buffer, char *delim)
{
	char *token, *bufc;
	int x = 0;
	int w_ct = word_count(buffer);

	char **words = malloc(sizeof(char*) * (w_ct + 1));
	bufc = _strdup(buffer);
	if (!bufc)
		return (NULL);

	token = _strtok(bufc, delim);

	while (token)
	{
		words[x] = malloc(sizeof(char) * _strlen(token) + 1);
		if (!*words)
		{
			free(words[x]);
			free(words);
			return (NULL);
		}
		_strcpy(words[x], token);
		x++;
		token = _strtok(NULL, delim);
	}
	words[x] = NULL;
	return (words);
}
