#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			/*Print characters directly using write function*/
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++; /*Move past the '%'*/
			char specifier = *format;

			switch (specifier)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1);
						printed_chars++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str)
						{
							write(1, str, 1);
							printed_chars++;
							str++;
						}
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						printed_chars++;
						break;
					}
				default:
					/*Print the invalid specifier as is*/
					write(1, "%", 1);
					write(1, &specifier, 1);
					printed_chars += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);

	return printed_chars;
}
