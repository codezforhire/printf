#include "main.h"

/**
 * get_wdt - Calculates the wdt for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: wdt.
 */
int get_wdt(const char *format, int *i, va_list list)
{
	int cursor;
	int wdt = 0;

	for (cursor = *i + 1; format[cursor] != '\0'; cursor++)
	{
		if (is_digit(format[cursor]))
		{
			wdt *= 10;
			wdt += format[cursor] - '0';
		}
		else if (format[cursor] == '*')
		{
			cursor++;
			wdt = arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cursor - 1;

	return (wdt);
}
