#include "main.h"

/**
 * _strtok - This function to break string into smaller tokens
 * @str: The string to be tokenized
 * @delim: The delimeter
 * Return: The pointer to 1st token, NULL if no token found
 */

char *_strtok(char *str, const char *delim)
{
static char *token = NULL;
char *start;
if (str != NULL)
{
    token = str;
}
else if (token == NULL)
{
    return (NULL);
}

*start = token;
token = strpbrk(token, delim);
if (token != NULL)
{
    *token = '\0';
    token++;
}
return (start);
}
