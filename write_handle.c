#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_char - Prints a string
 * @a: char types.
 * @buff: buff array to handle print
 * @flags:  Calculates active flags.
 * @wdt: get wdt.
 * @press: press specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int handle_char(char c, char buff[],
	int flags, int wdt, int press, int sz)
{ /* char is stored at left and padind at buff's right */
	int i = 0;
	char pad = ' ';

	UNUSED(press);
	UNUSED(sz);

	if (flags & f_0)
		pad = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (wdt > 1)
	{
		buff[BUFF_sz - 1] = '\0';
		for (i = 0; i < wdt - 1; i++)
			buff[BUFF_sz - i - 2] = pad;

		if (flags & f_mi)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_sz - i - 1], wdt - 1));
		else
			return (write(1, &buff[BUFF_sz - i - 1], wdt - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * number - Prints a string
 * @neg: Lista of arguments
 * @ind: char types.
 * @buff: buff array to handle print
 * @flags:  Calculates active flags
 * @wdt: get wdt.
 * @press: press specifier
 * @sz: sz specifier
 *
 * Return: Number of chars printed.
 */
int number(int neg, int ind, char buff[],
	int flags, int wdt, int press, int sz)
{
	int len = BUFF_sz - ind - 1;
	char pad = ' ', sign = 0;

	UNUSED(sz);

	if ((flags & f_0) && !(flags & f_mi))
		pad = '0';
	if (neg)
		sign = '-';
	else if (flags & F_PLUS)
		sign = '+';
	else if (flags & F_SPACE)
		sign = ' ';

	return (write_n(ind, buff, flags, wdt, press,
		len, pad, sign));
}

/**
 * write_n - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: buff
 * @flags: Flags
 * @wdt: wdt
 * @prec: press specifier
 * @len: Number len
 * @pad: Pading char
 * @ext: Extra char
 *
 * Return: Number of printed chars.
 */
int write_n(int ind, char buff[],
	int flags, int wdt, int prec,
	int len, char pad, char ext)
{
	int i, pad_st = 1;

	if (pr== 0 && ind == BUFF_sz - 2 && buff[ind] == '0' && wdt == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (pr== 0 && ind == BUFF_sz - 2 && buff[ind] == '0')
		buff[ind] = pad = ' '; /* wdt is displayed with pading ' ' */
	if (pr> 0 && pr< len)
		pad = ' ';
	while (pr> len)
		buff[--ind] = '0', len++;
	if (ext != 0)
		len++;
	if (wdt > len)
	{
		for (i = 1; i < wdt - len + 1; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (flags & f_mi && pad == ' ')/* Asign extra char to left of buff */
		{
			if (ext)
				buff[--ind] = ext;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & f_mi) && pad == ' ')/* extra char to left of buff */
		{
			if (ext)
				buff[--ind] = ext;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(flags & f_mi) && pad == '0')/* extra char to left of pad */
		{
			if (ext)
				buff[--pad_st] = ext;
			return (write(1, &buff[pad_st], i - pad_st) +
				write(1, &buff[ind], len - (1 - pad_st)));
		}
	}
	if (ext)
		buff[--ind] = ext;
	return (write(1, &buff[ind], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @wdt: wdt specifier
 * @press: press specifier
 * @sz: sz specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int neg, int ind,
	char buff[],
	int flags, int wdt, int press, int sz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_sz - ind - 1, i = 0;
	char pad = ' ';

	UNUSED(neg);
	UNUSED(sz);

	if (press == 0 && ind == BUFF_sz - 2 && buff[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (press > 0 && press < len)
		pad = ' ';

	while (press > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flags & f_0) && !(flags & f_mi))
		pad = '0';

	if (wdt > len)
	{
		for (i = 0; i < wdt - len; i++)
			buff[i] = pad;

		buff[i] = '\0';

		if (flags & f_mi) /* Asign extra char to left of buff [buff>pad]*/
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else /* Asign extra char to left of pading [pad>buff]*/
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}

/**
 * write_p - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @len: len of number
 * @wdt: wdt specifier
 * @flags: Flags specifier
 * @pad: Char representing the pading
 * @ext: Char representing extra char
 * @pad_st: Index at which pading should start
 *
 * Return: Number of written chars.
 */
int write_p(char buff[], int ind, int len,
	int wdt, int flags, char pad, char ext, int pad_st)
{
	int i;

	if (wdt > len)
	{
		for (i = 3; i < wdt - len + 3; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (flags & f_mi && pad == ' ')/* Asign extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (ext)
				buff[--ind] = ext;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & f_mi) && pad == ' ')/* extra char to left of buff */
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (ext)
				buff[--ind] = ext;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flags & f_mi) && pad == '0')/* extra char to left of pad */
		{
			if (ext)
				buff[--pad_st] = ext;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pad_st], i - pad_st) +
				write(1, &buff[ind], len - (1 - pad_st) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (ext)
		buff[--ind] = ext;
	return (write(1, &buff[ind], BUFF_sz - ind - 1));
}
