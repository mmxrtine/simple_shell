#include "shell.h"

void read_command(char *string, size_t length)
{
	if (fgets(string, length, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_printf("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	string[strcspn(string, "\n")]= '\0'; /*removes newline*/
}
