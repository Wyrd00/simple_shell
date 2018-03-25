#include "shell.h"
/**
 * word_count - find word count
 * @s: pointer to string
 * Return: word count
 */

int word_count(char *s)
{
	if (!s)
		return (-1);
	int i = 0;
	int words = 1;
	char delim = ' ';

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == delim)
			words++;

	return (words);
}
