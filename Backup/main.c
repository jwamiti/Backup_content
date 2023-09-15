#include "main.h"
/**
 * main - This is my main function for the simple shell project
 * Return: 0 on success
 */
int main(int ac, char **argv)
{
        char *prompt = "Prompt $ ";
        char *buffer = NULL;
        char *arg[10];
        size_t buff_size = 0;
        ssize_t nread;
        int status;
        pid_t child_processID;

        (void)ac;
        (void)argv;
        while (1)
        {
        if(!(isatty(1)))
                printf("%s", prompt);
        nread = getline(&buffer, &buff_size, stdin);
        if (nread == -1)
        {
                free(buffer);
                termination();
        }
        remove_newline(buffer);
        /*arg[0] = strdup(buffer);*/
        tokenization_args(buffer, arg);

        /*print_any_string(buffer);*/
        child_processID = fork();
        if (child_processID == 0)
                executing(arg[0], arg);

        else if(child_processID < 0)
                termination_child();
        else
                /*print_any_string("i am parent");*/
                wait(&status);


        /*free(arg);*/
        }
        free(buffer);
        return (0);
}
