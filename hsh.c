#include "shell.h"
int line_num = 0;
/**
 * main - super simple shell
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	if (!argc)
		return (0);
	loop(argv[0]);
	return (0);
}
