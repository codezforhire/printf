#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */
			if (*format == '\0')
				break; /* Handle case where '%' is at the end */
			if (*format == 'c')
			{
				/* Handle character specifier */
				char c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				/* Handle string specifier */
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					write(1, s, 1);
					s++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				/* Handle literal '%' */
				write(1, "%", 1);
				printed_chars++;
			}
			/* Add more cases for other specifiers if needed */
		}
		else
		{
			write(1, format, 1); /* Print regular characters */
			printed_chars++;
		}
		format++; /* Move to the next character */
	}

	va_end(args);
	return printed_chars;
}
