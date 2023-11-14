#include "main.h"

/**
 * _strcat - This function to concatenate two strings
 * @src: source string
 * @dest: destination string
 * Return: pointer to the dest string
 */

char *_strcat(char *dest, char *src)
{
int l = 0;
int i = 0;
while (dest[l] != '\0')
{
    l++;
}
while (src[i] != '\0')
{
    dest[l + i] = src[i];
    i++;
}
dest[l + i] = '\0';
return (dest);
}
