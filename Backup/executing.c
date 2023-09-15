#include "main.h"
int executing(char *str, char **array)
{

        if(execve(str, array, NULL) == -1)
        {
                perror("Could not execute");
                exit(0);
        }
        return (0);
}
void termination_child()
{
        perror("Could not create child");
        exit(1);
}

void tokenization_args(char *str, char **argument)
{
        int counter = 0;
        argument[counter]= strtok(str, " \t\n");
        while(argument[counter] != NULL)
        {
                counter++;
                argument[counter] = strtok(NULL, " \t\n");
        }
        argument[counter] = NULL;
}
