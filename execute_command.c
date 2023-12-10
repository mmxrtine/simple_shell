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
		execlp(prompt, prompt, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}

	else
	{
		/*parent process*/
		wait(NULL);
	}

}
