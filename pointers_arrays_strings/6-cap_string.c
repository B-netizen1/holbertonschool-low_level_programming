#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	char *sep;
	int i;

	sep = "\t\n,;.!?\"(){}";
	for (i = 0; sep[i] != '\0'; i++)
	{
		if (c == sep[i])
			return (1);
	}

	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @s: the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (i == 0 || is_separator(s[i - 1]))
				s[i] = s[i] - ('a' - 'A');
		}
	}

	return (s);
}
