#include "main.h"

/**
* _strlen - To get the given string length
* @l: constant char
* Return: Length of the string
*/
int _strlen(char *l)
{
int len = 0;
while (*l != '\0')
{
len++;
l++;
}
return (len);
}

