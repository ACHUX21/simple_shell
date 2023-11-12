#include "main.h"
/**
 * saverinos - main part
 *
*/
int saverinos(char **array, char *cmd, int *exiting, char *argv)
{
	cmd = fullcmd(array[0]);
	if (strcmp(array[0], "env") == 0 || access(cmd, X_OK) != -1)
	{
		saver(array, cmd);
		return (1);
	}
	else
	{
		error_not_found(array[0], argv), *exiting = 127;
		return (2);
	}
	return (0);

}
/**
 * main - main function
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: number of arguments
*/
int main(int argc, char **argv)
{
	char **array, *buffer = NULL, *cmd = NULL;
	int num_of_char, exiting = 0, te = 0;
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
		pid = fork();
		if (pid == 0)
		{
			te = saverinos(array, cmd, &exiting, argv[0]);
			if (te == 1)
				break;
			else if (te == 2)
				exit(exiting);
		}
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
