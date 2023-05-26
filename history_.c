#include "shell.h"

/**
 * _myhistory - will display the history list
 *             and with line number, and will start from zero.
 * @info: structure tht contains potential argument, useed
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - applys alias to the string
 * @info: the struct of the parameters.
 * @str: the ailas string here.
 *
 * Return: will forever return 0 if success, and one if error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets the string to be alias
 * @info: a struct parameter
 * @str: the string that contains the alias
 *
 * Return: 0 if right, 1 if error
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - will prints the string of the alias
 * @node: the node of the alias
 *
 * Return: 0 if it works, 1 if its faulty
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - is the alias builtinside (the man alias)
 * @info:structure that contains a argument. used to have a
 *          constant function prototype.
 *  Return:  0
 */
int _myalias(info_t *info)
{
	int o = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (o = 1; info->argv[o]; o++)
	{
		p = _strchr(info->argv[o], '=');
		if (p)
			set_alias(info, info->argv[o]);
		else
			print_alias(node_starts_with(info->alias, info->argv[o], '='));
	}

	return (0);
}



