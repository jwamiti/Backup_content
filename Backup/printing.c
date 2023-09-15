#include "main.h"
/**
 * print_any_string - This function picks a string as an argument and prints it.
 * @str - passed string that we need to print
 * Return: count of the characters printed.
 */
int print_any_string(char *str)
{
        int number = 0;
        int counter = 0;

        if (str != NULL)
        {
                for (counter = 0; str[counter] != '\0'; counter++)
                {
                        _putcharacter(str[counter]);
                        ++number;
                }
        }
        return (number);
}
/**
 * _putcharacter - This function write a single character at a time
 * @character - Takes a character as a parameter.
 * Return: result of the write function.
 */
int _putcharacter(char character)
{
        return (write(1, &character, 1));
}
/**
 * termination - This function is called anytime we need to terminate the getline function
 * Return: void
 */
void termination()
{
        perror("Error Occured");
        exit(1);
}
/**
 * remove_newline - this is a custom function that takes the buffer string and strips off the new line character
 * @buffer: buffer string passed
 * Return: buffer string
 */
char *remove_newline(char *buffer)
{
        int q;

        for (q = 0; buffer[q] != '\0'; q++)
        {
                if (buffer[q] == '\n')
                {
                        buffer[q] = '\0';
                }
        }
        return (buffer);
}
