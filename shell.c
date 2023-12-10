#include "shell.h"

int main()
{
	char command[150];

	while (1)
	{
		display_prompt();
		user_input(command, sizeof(command));
        	execute_command(command);
	}
}
