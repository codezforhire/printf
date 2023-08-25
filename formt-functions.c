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
