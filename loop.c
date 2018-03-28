#include "shell.h"
/**
 * loop - shell loop
 *
 */

void loop(char *program)
{
	char *line;
	char **args;
	int status, x;

	env = _environ();
	main_path = make_path();

	status = 1;
	while (status)
	{
		line_num++;
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		if (line[0] == EOF)
		{
			hsh_exit(NULL, line);
		}
		args = tokenize(line, "\n ");
		if (check_builtin(args, line) == 1)
			status = execute(args, program);
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
	free_path(env);

}
