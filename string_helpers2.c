#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--str;
	return (ptr);
}/*Done*/

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 **_strchr - search character in a string
 *@str: string to search
 *@c: character to search
 *Return: pointer location
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
/**
 **_strncpy - copies a string
 *@dest: destination string to copy-to
 *@src: source string
 *@n: number of characters to copy
 *Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j, count = n - 1;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < count)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}/* Done */
/**
 **_strncat - concatenates two strings
 *@dest: destination string
 *@src: source string
 *@n: amount of character to be concate
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}/* Done */
