#include "shell.h"
/**
 * word_count - find word count
 * @s: pointer to string
 * Return: word count
 */

int word_count(char *s)
{
	int i = 0;
	int words = 0;
	/*int s_len = _strlen(s);*/
	char *delim = " ";

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == *delim)
			words++;

	return (words);
}
