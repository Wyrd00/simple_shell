#include "shell.h"

void __error(char **args, char *cmd, int code)
{
	char *str_num;
	str_num = _itoa(line_num);
//	printf("line_num = %d\n", line_num);
//	printf("arg len - %d\n", _strlen(args[0]));
//	printf("str num - %s\n", str_num);
//	printf("str_num len - %d\n", _strlen(str_num));
//	printf("cmd len - %d\n", _strlen(cmd));

	write(STDOUT_FILENO, cmd, _strlen(cmd));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, str_num, _strlen(str_num));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));

	if (code == 1)
		write(STDOUT_FILENO, ": not found\n", 13);
	if (code == 2)
		write(STDOUT_FILENO, ": command not found\n", 21);
	if (code == 3)
		write(STDOUT_FILENO, "No such file\n", 14);
}
