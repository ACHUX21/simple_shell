#ifndef SHELL_H
#define SHELL_H

extern char **environ;


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include <string.h>
#include<sys/wait.h>
#include <limits.h>
#include <sys/stat.h>


char *findenv_value(const char *name);
char **translate_array(char *buffer);
int set_env(const char *name, const char *value, int or);
char *fullcmd(char *cmd);
ssize_t read_command(char **buffer, size_t *buffer_size);
void printenv(void);
void free_array(char **array);
void error_not_found(char *cmd, char *argv);
int another(char *array);
int _atoi(char *s);
void exit_error(int number, char *argv);
void exit_error_char(char *number, char *argv);
void print_number(int n);
int _putchar(char c);
int has_number(char *s);



#endif
