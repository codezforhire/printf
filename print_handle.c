
#include "main.h"
/**
 * print - Prints an argument based on its type
 * @formate: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buff: buff array to handle print.
 * @flags: Calculates active flags
 * @wdt: get wdt.
 * @press: press specification
 * @sz: sz specifier
 * Return: 1 or 2;
 */
int handle_print(const char *formate, int *ind, va_list list, char buff[],
	int flags, int wdt, int press, int sz)
{
	int i, len = 0, chars = -1;
	formate types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; types[i].formate != '\0'; i++)
		if (formate[*ind] == types[i].formate)
			return (types[i].fn(list, buff, flags, wdt, press, sz));

	if (types[i].formate == '\0')
	{
		if (formate[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (formate[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (wdt)
		{
			--(*ind);
			while (formate[*ind] != ' ' && formate[*ind] != '%')
				--(*ind);
			if (formate[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &formate[*ind], 1);
		return (len);
	}
	return (chars);
}

