#include "main.h"
/**
 * findenv_value - find the environment value associated
 * @name: the name of the environment variable
 * Return: the value of the environment variable
*/
char *findenv_value(const char *name)
{
	int i = 0;
	char *keyname, *buffer, *value;

	while (environ[i])
	{
		buffer = strdup(environ[i]);
		keyname = strtok(buffer, "=");
		if (keyname != NULL && strcmp(keyname, name) == 0)
		{
			value = strdup(strtok(NULL, "\n"));
			free(buffer);
			return (value);
		}
		free(buffer);
		i++;
	}
	return (NULL);
}

/**
 * fullcmd - Function to find the full command line
 * @cmd: command line
 * Return: command line full command
*/
char *fullcmd(char *cmd)
{

	char *fullcmd;
	char *spath;
	char *path = findenv_value("PATH");

	spath = strtok(path, ":");
	if (spath == NULL)
		return (cmd);
	while (spath)
	{
		fullcmd = malloc(strlen(spath) + strlen(cmd) + 2);
		strcpy(fullcmd, spath), strcat(fullcmd, "/"), strcat(fullcmd, cmd);
		if (access(fullcmd, X_OK) == 0)
		{
			free(path);
			return (fullcmd);
		}
		free(fullcmd);
		spath = strtok(NULL, ":");
	}
	free(path);
	return (cmd);
}
/**
 * set_env - set the environment variable associated
 * @name: the name of the environment variable
 * @value: the value of the environment variable
 * @or: ovewrite the value of the environment variable
 * Return: 0 if successful and -1 otherwise
*/
int set_env(const char *name, const char *value, int or)
{
	int i = 0, len = strlen(name);
	char *keyname;

	if (!name || !value)
		return (-1);

	while (environ[i++])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			if (or)
			{
				keyname = malloc(len + strlen(value) + 2);
				if (!keyname)
					return (-1);
				strcpy(keyname, name);
				strcat(keyname, "=");
				strcat(keyname, value);
				environ[i] = keyname;
				free(keyname);
				return (0);
			}
			return (0);
		}
	}
	keyname = malloc(len + strlen(value) + 2);
	strcpy(keyname, name);
	strcat(keyname, "=");
	strcat(keyname, value);
	environ[i] = keyname;
	environ[i + 1] = NULL;
	free(keyname);
	return (0);
}
/**
 * unset_env - remove the environment
 * @name: the name of the environment
 * Return: 0 on success and -1 on failure
*/
int unset_env(const char *name)
{
	int i = 0, len = strlen(name);
	char *keyname;

	if (!name)
		return (-1);

	while (environ[i++])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			keyname = malloc(len + 1);
			if (!keyname)
				return (-1);
			strcpy(keyname, name);
			environ[i] = keyname;
			return (0);
		}
	}
	return (0);
}
