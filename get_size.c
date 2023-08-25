#include "main.h"

/**
 * get_sz - Calculates the sz to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_sz(const char *format, int *i)
{
	int cursor = *i + 1;
	int sz = 0;

	if (format[cursor] == 'l')
		sz = S_LONG;
	else if (format[cursor] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = cursor - 1;
	else
		*i = cursor;

	return (sz);
}

