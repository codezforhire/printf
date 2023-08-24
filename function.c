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
			/* Print characters directly using write function */
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++; /* Move past the '%' */
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
				int temp = num;
				int num_chars = 0;

				if (num < 0) {
					write(1, "-", 1);
					printed_chars++;
					num = -num;
				}

				/* Count the number of digits in the number */
				do {
					temp /= 10;
					num_chars++;
				} while (temp != 0);

				char num_str[num_chars + 1]; /* +1 for the null terminator */
				num_str[num_chars] = '\0';

				/* Convert the integer to a string in reverse order */
				for (int i = num_chars - 1; i >= 0; i--) {
					num_str[i] = num % 10 + '0';
					num /= 10;
				}

				write(1, num_str, num_chars);
				printed_chars += num_chars;
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
