#include "shell.h"
/**
 * loop - shell loop
 *
 */

void loop(void)
{
	char *line;
	char **args;
	int status;

	status = 1;
	main_path = make_path();
	while (status)
	{
		line = read_line();
		args = tokenize(line, " ");
		if (check_builtin(args) == 1)
			status = execute(args);

		free(line);
		free(args);
	}
	free(main_path);
}
