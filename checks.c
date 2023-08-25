#include "main.h"

/**
 * conversion - selects the appropriate conversion
 * function for a given format specifier.
 * @c: the format specifier character
 *
 * Return: a pointer to the appropriate conversion function,
 * or NULL if no matching function is found
 */
int (*conversion(char c))(va_list *)
{
	format_t formats[] = {
		{'c', get_char},
		{'s', get_string},
		{'d', get_int},
		{'i', get_int},
		{'b', get_binary},
		{'x', get_hex_lower},
		{'X', get_hex_upper},
		{'o', get_octal},
		{'u', get_unsigned},
		{'S', get_conv_string},
		{'p', get_pointer},
		{'r', get_reverse},
		{'R', get_rot}};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (formats[i].fo == c)
			return ((formats[i].print));
	}

	return (NULL);
}
