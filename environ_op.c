#include "shell.h"

/**
 * _environ - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _environ(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenviron - gets environ variable value
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenviron(info_t *info, const char *name)
{
	list_t *in_node = info->env;
	char *c;

	while (in_node)
	{
		c = starts_with(in_node->str, name);
		if (c && *c)
			return (c);
		in_node = in_node->next;
	}
	return (NULL);
}

/**
 * _setenviron - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _setenviron(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenviron - Remove an environment variable
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _unsetenviron(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *in_node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&in_node, environ[i], 0);
	info->env = in_node;
	return (0);
}
