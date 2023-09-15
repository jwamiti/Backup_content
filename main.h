#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int _builtInCmd(char **arg);


#endif
