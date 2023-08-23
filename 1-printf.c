#include "main.h"

int _printf_helper(const char *format, va_list *ptr);

/**
 * _printf - Build out the printf function
 * @format: string passed with possible format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ptr;

	if (!format)
		return (-1);
	va_start(ptr, format);

	return (_printf_helper(format, &ptr));
}

/**
 * _printf_helper - prints formatted output to stdout
 * @format: A string containing zero or more format specifiers
 * @ptr: A pointer to a va_list of arguments to be printed
 *
 * Return: The number of characters printed on success, -1 on failure
 */
int _printf_helper(const char *format, va_list *ptr)
{
	int (*print)(va_list *);
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			while (*(++format) == ' ')
				;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				print = conversion(*format);
				if (print == NULL)
				{
					if (!*format)
						return (-1);
					_putchar('%');
					_putchar(*format);
					count += 2;
				}
				else
					count += print(ptr);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(*ptr);
	return (count);
}
