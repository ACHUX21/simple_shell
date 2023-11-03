#include "main.h"
/**
 * main - main function
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: number of arguments
*/
int main(int argc, char **argv)
{
	char **array, *buffer, *cmd;
	size_t buffer_size;
	int num_of_char, i, status, exit_code;
	pid_t pid;

	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		num_of_char = getline(&buffer, &buffer_size, stdin);

		if (num_of_char == -1)
			exit(0);
		array = translate_array(buffer);
		if (array[0] == NULL)
			continue;
		if (strcmp(array[0], "exit") == 0)
			exit(0);
		if (strcmp(array[0], "env") == 0)
		{
			printenv();
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			cmd = fullcmd(array[0]);
			if (access(cmd, X_OK) != -1)
				execve(cmd, array, environ);
			else
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd), status = 127;
		}
		else
			wait(&status);
		i = 0;
		free(array);
	}
}
