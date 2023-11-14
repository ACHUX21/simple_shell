#include "main.h"

/**
 * _strcmp - This function to compare two strings
 * @str1: Value 1
 * @str2: Value 2
 * Return: The differ btw the values(str1[i] - str2[i]), or 0 if equal.
 */

int _strcmp(char *str1, char *str2)
{
int i = 0;
while (str1[i] == str2[i])
{
	if (str1[i] == '\0')
	{
		return (0);
	}
	i++;
}
return (str1[i] - str2[i]);
}
