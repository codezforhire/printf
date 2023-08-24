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
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				while (*str)
				{
					write(1, str, 1);
					printed_chars++;
					str++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int is_negative = 0;

				if (num < 0) {
					write(1, "-", 1);
					printed_chars++;
					is_negative = 1;
					num = -num;
				}

				if (num == 0) {
					write(1, "0", 1);
					printed_chars++;
				} else {
					int num_digits = 0;
					int temp = num;

					while (temp > 0) {
						temp /= 10;
						num_digits++;
					}

					char num_str[num_digits + 1];
					num_str[num_digits] = '\0';

					for (int i = num_digits - 1; i >= 0; i--) {
						num_str[i] = num % 10 + '0';
						num /= 10;
					}

					write(1, num_str, num_digits);
					printed_chars += num_digits;
				}
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				printed_chars++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				printed_chars += 2;
			}
		}
		format++;
	}

	va_end(args);
	return printed_chars;
}
