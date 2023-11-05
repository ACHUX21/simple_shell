#include "main.h"
/**
 * free_array - free the array from memory
 * @array: the array to free
*/
void free_array(char **array)
{
	int j;

	if (!array)
		return;
	for (j = 0; array[j] != NULL; j++)
		free(array[j]);
	free(array);
}
/**
 * translate_array - translate the array
 * @buffer: the array to translate
 * Return: the array to translate
*/
char **translate_array(char *buffer)
{
	char **arr;
	char *cmd;
	int j = 0;

	arr = malloc(sizeof(char *) * 1024);

	cmd = strtok(buffer, " \n\t");
	while (cmd != NULL)
	{
		arr[j] = cmd;
		cmd = strtok(NULL, " \n\t");
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
/**
 * printenv - print the environment
*/
void printenv(void)
{
	while (*environ)
	{
		write(1, *environ, strlen(*environ)), write(1, "\n", 1);
		environ++;
	}
}
/**
 * _atoi -  Convert a string to an integer
 * @s: String to convert
 * Return: integer
 */

int _atoi(char *s)
{
	int sign = 1, j = 0;
	unsigned int res = 0;

	while (!(s[j] <= '9' && s[j] >= '0') && s[j] != '\0')
	{
		if (s[j] == '-')
			sign *= -1;
		j++;
	}
	while (s[j] <= '9' && (s[j] >= '0' && s[j] != '\0'))
		res = (res * 10) + (s[j] - '0'), j++;
	res *= sign;
	return (res);
}
