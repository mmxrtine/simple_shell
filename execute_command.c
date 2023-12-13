#include "shell.h"


extern char **environ; 

void execute_command(const char *prompt) 
{
	int arg_count = 0;
    	char *args[100];
	char *paths[] = {"/bin", "/usr/bin", NULL};
	int i;

	pid_t child_pid = fork();

    	if (child_pid == -1) 
	{
        perror("fork");
        exit(EXIT_FAILURE);
	}

    	else if (child_pid == 0) 
	{
        /* Split the command and arguments */
        char *token = strtok((char *)prompt, " ");
        while (token != NULL && arg_count < 99) 
	{
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
	}
        args[arg_count] = NULL; /* Null-terminate the array */


        /* Try to execute the command with its arguments from specified paths */
	for ( i = 0; paths[i] != NULL; i++)
	{	
	       	char path[100];
            	strcpy(path, paths[i]);
            	strcat(path, "/");
            	strcat(path, args[0]);
            	execve(path, args, environ);
	}
}

