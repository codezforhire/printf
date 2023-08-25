#include "main.h"

/**
 * get_char - prints a single character to stdout
 * @character: a pointer to the character to print
 *
 * Return: the number of characters printed (always 1)
 */
int get_char(va_list *character)
{
	_putchar(va_arg(*character, int));
	return (1);
}

/**
 * get_string - passes a string through
 * @string: string to pass through
 *
 * Return: unmodified string
 */
int get_string(va_list *string)
{
	char *str;
	int count;

	str = va_arg(*string, char *);
	count = 0;

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str && str[count])
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}



#include "main.h"

/**
 * get_int - print integer to stdout
 * @arg: pointer to va_list contain integer argument
 *
 * Return: number of characters printed
 */
int get_int(va_list *arg)
{
	long int digits, temp, count, arg_int;
	char arr[32];

	arg_int = va_arg(*arg, int);
	digits = count = 0;
	if (arg_int < 0)
	{
		_putchar('-');
		arg_int *= -1;
		count++;
	}
	temp = arg_int;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	if (arg_int == 0)
	{
		_putchar('0');
		count++;
	}
	while (arg_int > 0)
	{
		arr[digits - temp] = arg_int % 10 + 48;
		arg_int /= 10;
		count++;
		temp++;
	}
	temp = 0;
	while (++temp <= digits)
		_putchar(arr[temp]);
	return (count);
}
