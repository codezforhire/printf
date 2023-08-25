#include "main.h"

/**
 * get_press - Calculates the press for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list:  of arguments.
 *
 * Return :press.
 */
int get_press(const char *format, int *i, va_list list)
{
	int cursor = *i + 1;
	int press = -1;

	if (format[cursor] != '.')
		return (press);

	press = 0;

	for (cursor += 1; format[cursor] != '\0'; cursor++)
	{
		if (is_digit(format[cursor]))
		{
			press *= 10;
			press += format[cursor] - '0';
		}
		else if (format[cursor] == '*')
		{
			cursor++;
			press = va_arg(list, int);
			break;		}
		else
			break;
	}

	*i = cursor-1;

	return (press);
}

