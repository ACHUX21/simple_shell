#include "main.h"
/**
 * error_not_found - Prints an error message when a command is not found
 * @cmd: The command that was not found
 * @argv: The name of the program
 */
void error_not_found(char *cmd, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * exit_error - Prints an error message when an illegal exit number is provided
 * @number: The illegal exit number
 * @argv: The name of the program
 */
void exit_error(int number, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	print_number(number);
	write(STDERR_FILENO, "\n", 1);
}

/**
 * exit_error_char - Prints an error message when
 * @number: The illegal exit number as a string
 * @argv: The name of the program
 */
void exit_error_char(char *number, char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
	write(STDERR_FILENO, number, strlen(number));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * exiting_advance - Handles the process of exiting the program
 * @array: The arguments passed to the exit command
 * @exiting: A pointer to the exit status variable
 * @argv: The name of the program
 */
void exiting_advance(char **array, int *exiting, char *argv)
{
	if (array[1] && has_number(array[1]))
		*exiting = _atoi(array[1]);
	else if (array[1])
		exit_error_char(array[1], argv), *exiting = 2;
	free(array);
}
