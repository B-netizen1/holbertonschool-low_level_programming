#include <stddef.h>
#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the string to locate
 *
 * Return: a pointer to the first occurrence of c in s,
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}

	return (s);
}
