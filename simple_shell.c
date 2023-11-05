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
	int num_of_char, status, exiting;
	size_t buffer_size;
	pid_t pid;

	(void)argc;
	while (1)
	{
		if (isatty(0))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		num_of_char = getline(&buffer, &buffer_size, stdin);
		if (num_of_char == -1)
			free(buffer), exit(0);
		array = translate_array(buffer);
		if (!array[0])
		{
			free(array);
			continue;
		}
		if (!strcmp(array[0], "exit"))
		{
			if (array[1] && has_number(array[1]))
				exiting = _atoi(array[1]);
			else if (array[1])
				exit_error_char(array[1], argv[0]), exiting = 2;
			free(array);
			break;
		}
		if (!strcmp(array[0], "env"))
		{
			printenv(), free(array);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			cmd = fullcmd(array[0]);
			if (access(cmd, X_OK) != -1)
			{
				execve(cmd, array, environ);
				break;
			}
			else
				exiting = 127, error_not_found(cmd, argv[0]);
		}
		else
			wait(&status);
		free(array);
	}
	if (isatty(0))
		free(buffer);
	if (exiting < 0)
		exit_error(exiting, argv[0]), exiting = 2;

	exit(exiting);
}
void error_not_found(char *cmd, char *argv)
{
    write(STDERR_FILENO, argv, strlen(argv));
    write(STDERR_FILENO, ": 1: ", 5);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, ": not found\n", 12);
	exit(0);
}
void exit_error(int number, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	print_number(number);
	write(STDERR_FILENO, "\n", 1);
}
void exit_error_char(char *number, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	write(STDERR_FILENO, number, strlen(number));
	write(STDERR_FILENO, "\n", 1);
}