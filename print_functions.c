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

/**
 * print_double_percent - prints a percent '%'
 * @args: argument to print
 *
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
 *
 * Return: digits
 */
int print_int(va_list args) 
{
	int i; 
	int num = va_arg(args, int);
	int temps = num;
	int digits = 0;
	char num_str[1023];
	  
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
