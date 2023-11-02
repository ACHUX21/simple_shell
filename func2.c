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
 * 
*/
char **translate_array(char *buffer) // buf == " "
{
    char **arr;
    char *cmd;
    int i = 0;

	arr = malloc(sizeof(char *) * 2048);
    if (!arr)
    {
        free(arr);
        return (NULL);
    }

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
