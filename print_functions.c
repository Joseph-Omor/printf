#include "main.h"

/**
 * print_char - prints character
 * @args: argment to print
 *
 * Return: 1.
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints strings
 * @args: argument to print
 *
 * Return: length of string.
 */
int print_string(va_list args)
{
	char *str;
	int str_len;

	str = va_arg(args, char *);
	str_len = 0;

	while (str[str_len] != '\0')
	{
		str_len++;
	}
	write(1, str, str_len);
	return (str_len);
}
