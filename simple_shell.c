#include "main.h"
int main(int argc, char **argv)
{
	char **array ,*buffer, *cmd;
	size_t buffer_size;
	int num_of_char, i , status;
	pid_t pid;

	while (1)
	{
		write(0, "#cisfun$ ", 9);
		num_of_char = getline(&buffer, &buffer_size, stdin);
		printf("%s\n", buffer);
		printf("hey\n");
        if (buffer[0] == '\0')
		{
			write(2, "\n", 1);
			free(buffer);
			continue;
		}
		printf("%c\n", buffer[0]);
		if (num_of_char == -1)
            exit(0);
		array = translate_array(buffer);
		if (strcmp(array[0], "exit") == 0)
			exit(0);

		pid = fork();
		if (pid == 0)
		{
			cmd = fullcmd(array[0]);
            if (access(cmd, R_OK) != -1)
                execve(cmd, array, environ);
			else
    			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd);
        }
		else
			wait(&status);
		i = 0;
		free(array);
	}
	return (0);
}
