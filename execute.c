#include "shell.h"
/**
 * execute - executes a program
 * @args: a double pointer of command line arguments
 *
 * Return: always returns 1
 */

int execute(char **args)
{
	pid_t child_pid;
	int status;
	char *result;

	child_pid = fork();
	if (child_pid == 0)
	{
		if(args[0][0] == '/')
		{
			if (execve(args[0], args, environ) == -1)
				perror("Error: failed to execute program");
		}
		else
		{
			result = (check_path(main_path, args[0]));
			if (!result)
				perror("You done goofed!");
			if (execve(result, args, environ) == -1)
				perror("Error: failed to execute program");
		}

	}
	else if (child_pid == -1)
	{
		perror("Error: fork failed");
		exit(99);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (1);
}
