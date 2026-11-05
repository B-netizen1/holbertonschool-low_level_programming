#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i;
	int j;
	int p;

	i = 0;
	while (i <= 9)
	{
		_putchar('0');
		j = 1;
		while (j <= 9)
		{
			p = i * j;
			_putchar(',');
			_putchar(' ');
			if (p < 10)
				_putchar(' ');
			else
				_putchar(p / 10 + '0');
			_putchar(p % 10 + '0');
			j++;
		}
		_putchar('\n');
		i++;
	}
}
