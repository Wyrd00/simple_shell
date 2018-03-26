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

	env = _environ();
	main_path = make_path();
  
	status = 1;
	while (status)
	{
		line = read_line();
		args = tokenize(line, " ");
		if (check_builtin(args, line) == 1)
			status = execute(args);
		x = 0;
		while (args[x] != NULL)
		{
				free(args[x]);
				x++;
		}
		free(line);
		free(args);
	}
	free_path(main_path);
	free(env);
}
