#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* _strdup - duplicate string to a new memory locat space
* @str: constant char
* Return: 0 or NULL if memory allocation failed
*/

char *_strdup(char *str)
{
int i = 0;
while (str[i] != '\0')
i++;
char *new_str = malloc(sizeof(char) * (i + 1));
if (new_str == NULL)
{
    return (NULL);
}
strcpy(new_str, str);
return (new_str);
}
