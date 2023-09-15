#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int print_any_string(char *str);
int _putcharacter(char character);
void termination();
char *remove_newline(char *buffer);
int executing(char *str, char **array);
void termination_child();
void tokenization_args(char *str, char **argument);


#endif
