#include "main.h"

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	char buffer[BUFF_SIZE];  /* Buffer to hold the formatted output */
	int count = 0;           /* To keep track of characters printed */

	for (int i = 0; format[i] != '\0'; i++) {
		if (format[i] == '%') {
			i++;  /* Move past the '%' */

			/* Get flags, width, precision, and size from format */
			int flags = get_flags(format, &i);
			int width = get_width(format, &i, args);
			int precision = get_precision(format, &i, args);
			int size = get_size(format, &i);

			/* Find the corresponding function for the specifier */
			int found = 0;
			for (int j = 0; format_specifiers[j].fmt != '\0'; j++) {
				if (format_specifiers[j].fmt == format[i]) {
					count += format_specifiers[j].fn(args, buffer, flags, width, precision, size);
					found = 1;
					break;
				}
			}

			/* If no valid specifier is found, print the '%' character */
			if (!found) {
				putchar('%');
				count++;
			}
		} else {
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return count;
}

int main() {
	_printf("Hello, %s! This is a %c and a percent sign %%.\n", "User", 'C');
	return 0;
}
