#include "shell.h"

void execute_command(const char *prompt)
{
	pid_t child_pid = fork(); /*create a child process*/

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if (child_pid == 0) /*child process*/
	{
		/* construct full path */
		char *path[100];
		int path_count = 0;

		char *token = strtok((char *)prompt, " ");
		while (token != NULL && path_count < 99)
		{
			path[path_count++] = token;
			token = strtok(NULL, " ");
		}
		path[path_count] = NULL;

		execvp(path[0], path);

		perror("execvp");
		exit(EXIT_FAILURE);
	}

	else
	{
		/*parent process*/
		wait(NULL);
	}

}
