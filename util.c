#include "main.h"

/**
 * print - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa - Append ascci in hexadecimal code to buff
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int hexa(char ascii, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/*
	* The hexa format code is always 2 digits long
	 */
	if (ascii < 0)
		ascii *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[ascii / 16];
	buff[i] = map_to[ascii % 16];

	return (3);
}

/**
 * digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);

	return (0);
}

/**
 * convert - Casts a number to the specified size
 * @num: Number to be casted.
 * @sz: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_number(long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_sz_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @sz: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_unsgnd(unsigned long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

