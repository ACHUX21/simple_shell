#include "main.h"
/**
 * main - main function
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: number of arguments
*/
int main(int argc, char **argv)
{
	char **array, *buffer = NULL, *cmd;
	int num_of_char, exiting = 0;
	size_t buffer_size;
	pid_t pid = 0;

	for (;;)
	{
		if (isatty(0))
			write(STDIN_FILENO, "<achux21> ", 10);
		num_of_char = getline(&buffer, &buffer_size, stdin);
		(num_of_char == -1) ? (free(buffer), exit(0)) : (void)0;
		array = translate_array(buffer);
		if (!array[0])
		{
			free(array);
			continue;
		}
		if (!strcmp(array[0], "exit"))
		{
			exiting_advance(array, &exiting, argv[0]);
			break;
		}
		cmd = fullcmd(array[0]);
		if (cmd == NULL)
		{
			error_not_found(array[0], argv[0]), exiting = 127;
			continue;
		}
		pid = fork();
		if (pid == 0)
			saver(array, cmd), exit(0);
		else
			wait_child(&exiting);
		free(array), (void)argc;
	}
	free(buffer);
	if (exiting < 0)
		exit_error(exiting, argv[0]), exiting = 2;
	exit(exiting);
}
/**
 * saver - Function That saved me from betty
 * @array: array
 * @cmd: cmd
*/
void saver(char **array, char *cmd)
{
		if (strcmp(array[0], "env") == 0)
			printenv();
		else
			execve(cmd, array, environ);
		free(array);
}
