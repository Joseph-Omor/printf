#include "main.h"

/**
 * print_double_percent - prints a percent '%'
 * @args: argument to print
 * Return: 1.
 */
int print_double_percent(va_list args)
{
	(void)args;

	write(1, "%%", 1);
	return (1);
}

/**
 * print_int - a function that print digit
 * @args: argument to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int i;
	int num = va_arg(args, int);
	int temps = num;
	int digits = 0;
	char num_str[1024];

	if (num < 0)
	{
		write(1, "-", 1); /* Print negativesign for negative numbers*/
		num = -num; /* convert negative number to positive */
	}

	/* count the number of digits */
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temps > 0)
	{
		temps /= 10;
		digits++;
	}

	/* convert digits to characters and point */
	num_str[digits] = '\0';
	for (i = digits - 1; i >= 0; i--)
	{
		num_str[i] = '0' + (num % 10);
		num /= 10;
	}
	write(1, num_str, digits);
	return (digits);
}
