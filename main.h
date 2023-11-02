#ifndef SHELL_H
#define SHELL_H

extern char **environ;


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<string.h>
#include<sys/wait.h>
#include <limits.h>
#include <sys/stat.h>

char *findenv_value(const char *name);
char **translate_array(char *buffer);
int set_env(const char *name, const char *value, int or);
char *fullcmd(char *cmd);
ssize_t read_command(char **buffer, size_t *buffer_size);

/* free memory leak*/
void free_array(char **array);


#endif
