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

	while (1)
	{
		if (isatty(0))
			write(STDIN_FILENO, "<achux21> ", 10);
		num_of_char = getline(&buffer, &buffer_size, stdin);
		(num_of_char == -1) ? (free(buffer), exit(0)) : (void)0;
		array = translate_array(buffer);
		if (!array[0])
			continue;
		if (!strcmp(array[0], "exit"))
		{
			exiting_advance(array, &exiting, argv[0]);
			break;
		}
		pid = fork();
		if (pid == 0)
		{
			cmd = fullcmd(array[0]);
			if (strcmp(array[0], "env") == 0 || access(cmd, X_OK) != -1)
			{
				saver(array, cmd);
				break;
			}
			else
				error_not_found(cmd, argv[0]), exiting = 127, exit(exiting);
		}
		else
			wait_child(&exiting);
		free(array), (void)argc;
	}
	isatty(0) ? free(buffer) : (void)0;
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
