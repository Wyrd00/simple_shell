#include "shell.h"
/**
 * loop - shell loop
 *
 */

void loop(void)
{
	char *line;
	char **args;
	int status, x;

	status = 1;
	main_path = make_path();
	while (status)
	{
		line = read_line();
		args = tokenize(line, " ");
		free(line);
		if (check_builtin(args) == 1)
			status = execute(args);
		x = 0;
		while (args[x] != NULL)
		{
				free(args[x]);
				x++;
		}
		free(args);
	}
	free_path(main_path);
}
