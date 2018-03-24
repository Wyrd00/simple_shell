#include "shell.h"
/**
 * main - super simple shell
 *
 * Return: always 0
 */
int main(void)
{
	main_path = make_path();
	loop();
	free_path(main_path);
	return (0);
}
