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
		status = execute(args);
	}
	free (main_path);
}
