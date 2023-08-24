#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * str_len - calculates the length of a string.
 * @str: pointer to the character array.
 *
 * Return: length of the string
 */

int str_len(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}

	return (i);
}
