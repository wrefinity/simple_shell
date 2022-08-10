#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * str_free - frees a string of strings
 * @str: string to free
 */
void str_free(char **str)
{
	char **s = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(s);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @o_siz: byte size of previous block
 * @n_siz: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int o_siz, unsigned int n_siz)
{
	char *p;

	if (!ptr)
		return (malloc(n_siz));
	if (!n_siz)
		return (free(ptr), NULL);
	if (n_siz == o_siz)
		return (ptr);

	p = malloc(n_siz);
	if (!p)
		return (NULL);

	o_siz = o_siz < n_siz ? o_siz : n_siz;
	while (o_siz--)
		p[o_siz] = ((char *)ptr)[o_siz];
	free(ptr);
		return (p);
}


/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
