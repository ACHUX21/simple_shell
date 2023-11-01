#include "main.h"
int main(int argc, char **argv)
{
	char **array;
	char *buffer;
	char *cmd;
	size_t buffer_size;
	int num_of_char;
	char *flag;
	int i;
	pid_t pid;
	int status;


	while (1)
	{
		// write(1, "#cisfun$ ", 9);
		num_of_char = getline(&buffer, &buffer_size, stdin);
		if (num_of_char == -1)
		{
            exit(0);
		}
		array = translate_array(buffer);
		if (strcmp(array[0], "exit") == 0)
			exit(0);

		pid = fork();
		if (pid == 0)
		{
			cmd = fullcmd(array[0]);
            if (cmd)
                execve(cmd, array, environ);
			else
    			fprintf(stderr, "%s: command not found\n", array[0]);
        }
		else
			wait(&status);
		i = 0;
		free(array);

	}
}
