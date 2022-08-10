#include "shell.h"

/**
 * **str_word - splits a string into words
 * @str: string to split
 * @del: delimeter string
 * Return: a pointer to array of strings else null
 */

char **str_word(char *str, char *del)
{
	int i, j, k, m, nwords = 0;
	char **tokens;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], del) && (is_delim(str[i + 1], del) || !str[i + 1]))
			nwords++;

	if (nwords == 0)
		return (NULL);
	tokens = malloc((nwords + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (is_delim(str[i], del))
			i++;
		k = 0;
		while (!is_delim(str[i + k], del) && str[i + k])
			k++;
		tokens[j] = malloc((k + 1) * sizeof(char));
		if (!tokens[j])
		{
			for (k = 0; k < j; k++)
				free(tokens[k]);
			free(tokens);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			tokens[j][m] = str[i++];
		tokens[j][m] = 0;
	}
	tokens[j] = NULL;
	return (tokens);
}

/**
 * **str__word - splits a string into words
 * @str: the input string
 * @del: the delimeter
 * Return: strings pointer else nothing
 */
char **str__word(char *str, char del)
{
	int i, j, k, m, nwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != del && str[i + 1] == del) ||
		    (str[i] != del && !str[i + 1]) || str[i + 1] == del)
			nwords++;
	if (nwords == 0)
		return (NULL);
	s = malloc((1 + nwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (str[i] == del && str[i] != del)
			i++;
		k = 0;
		while (str[i + k] != del && str[i + k] && str[i + k] != del)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
