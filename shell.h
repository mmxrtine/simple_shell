#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt(void);
void execute_command(const char *prompt);
void _printf(const char *string);
void read_command(char *string, size_t length);
#endif
