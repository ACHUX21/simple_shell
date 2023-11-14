#include "main.h"

/**
* _strcpy - This fun is to copy the str pointed to by a source
* @src: The string copied from
* @dest: The string copied to
* Return: the str
*/
char *_strcpy(char *dest, const char *src)
{
int i = 0;
while (src[i] != '\0')
{
	dest[i] = src[i];
	i++;
}
dest[i] = '\0';
return (dest);
}
