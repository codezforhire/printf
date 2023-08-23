#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format - structure of function call
 * @fo: format (c, s, i, d)
 * @print: function to call
 */
typedef struct format
{
		char fo;
			int (*print)(va_list *);
} format_t;

int _printf(const char *format, ...);
int (*conversion(char c))(va_list *);
int get_char(va_list *character);
int get_string(va_list *string);
int get_int(va_list *arg);
int get_binary(va_list *num);
int get_hex_lower(va_list *num);
int get_hex_upper(va_list *num);
int get_octal(va_list *num);
int get_unsigned(va_list *num);
int get_conv_string(va_list *arg);
int get_pointer(va_list *num);
int get_reverse(va_list *reverse);
int get_rot(va_list *rot);

int _putchar(char c);
int str_len(char *str);

#endif /* MAIN_H */
