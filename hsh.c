#include "shell.h"
int line_num = 0;
/**
 * main - super simple shell
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	loop(argv[0]);
	return (0);
}
