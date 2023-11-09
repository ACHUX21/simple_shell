#include "main.h"
/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
		unsigned int num;

		if (n < 0)
		{
			_putchar('-');
			num = -n;
		}
		else
				num = n;
		if (num / 10)
			print_number(num / 10);
		_putchar((num % 10) + '0');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));

}
/**
 * has_number - check for if char have numbe
 * @s: arrar of char
 * Return: 0 or 1 in
*/
int has_number(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}
/**
 * wait_child - wait child
 * @exiting: Pointer
*/
void wait_child(int *exiting)
{
		int status;

	if (wait(&status) == -1)
		perror("wait"), exit(EXIT_FAILURE);
	if (WIFEXITED(status))
		*exiting = WEXITSTATUS(status);
}
