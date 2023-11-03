#include "main.h"
/**
 * free_array - free the array from memory
 * @array: the array to free
*/
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
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
	int i = 0;

	arr = malloc(sizeof(char *) * 1024);

	cmd = strtok(buffer, " \n\t");
	while (cmd != NULL)
	{
		arr[i] = cmd;
		cmd = strtok(NULL, " \n\t");
		i++;
	}
	arr[i] = NULL;
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
