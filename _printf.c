#include "shell.h"

void _printf(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
