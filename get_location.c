#include "main.h"

char *location(char *path, char *arg)
{
        char *path_cpy, *pathtoken, *filepath;
        char *delim = ":";
        /*char *buff;*/

        path_cpy = strdup(path);
        pathtoken = strtok(path_cpy, delim);
        filepath = malloc(strlen(arg) +strlen(pathtoken) + 2);
        while(pathtoken != NULL)
        {
                strcpy(filepath, pathtoken);
                strcat(filepath, "/");
                strcat(filepath, arg);
                strcat(filepath, "\0");

                if (access(filepath, X_OK) == 0)
                {
                        //free(path_cpy);
                        return (filepath);
                }
                pathtoken = strtok(NULL, delim);

        }
        free(filepath);
        free(path_cpy);

        /* totally removed
         * if (stat(arg,&buff) == 0)
        {
                return (arg);
        }*/

        return (NULL);
}


char *get_loc(char *arg)
{
        char *path;

        /*if(access("PATH", X_OK) == 0) also removed*/
                path = getenv("PATH");
        if(path)
        {
                path = location(path, arg);
 return (path);
        }
        return (NULL);
}
