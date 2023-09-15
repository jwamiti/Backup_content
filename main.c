#include "main.h"
/**
 *
 */
int main(int c, char **argv, char**env)
{
        /*char *prompt = "(Shell)$ ";*/
        char *buffer = NULL;
        size_t buffsize = 0;
        ssize_t n_chars;
        pid_t child_ID;
        int status, i, j;
        /*char *arg[] = {NULL, NULL};*/
        char *arg[11], *delim = " \n";
        char *path;/*after*/

        (void)c;
        (void)argv;
        while (1)
        {
                if(isatty(0))
                        printf("(Shell)$ ");
        n_chars = getline(&buffer, &buffsize, stdin);

        if(n_chars == -1)
        {
                _printstring("Exiting shell...");
                free(buffer);
                exit(0);
        }
        i = 0;
        while (buffer[i])
        {
                if(buffer[i] == '\n')
                {
                        buffer[i] = 0;
                }
                i++;
        }
        /*This was done with the first dection*/
        /*arg[0] = strdup(buffer);*/

        j = 0;
        arg[j] = strtok(buffer, delim);
        /*printf("%s", arg[j]);*/
        while(arg[j])
        {
                j++;
                arg[j] = strtok(NULL, delim);

        }
        arg[j] = NULL;

        path = get_loc(arg[0]);

        if (path == NULL)
        {
                if (_builtInCmd(arg) != 0)
                {
                        continue;
                }
                else
                        _printstring("command not found\n");
                continue;
        }

        child_ID = fork();
        if (child_ID < 0)
        {
                _printstring("Forking failed");
                free(buffer);
                exit(0);
        }
        else if (child_ID == 0)
        {
                /*if((execve(arg[0], arg, env)) == -1)*/
                if((execve(path, arg, env)) == -1)
                {
                        _printstring("command not found");
                }
        }
        else
        {
                wait(&status);


        /*_printstring(buffer);*/



        }
        }
        free(path);
        free(buffer);
        return (0);
}
                           