#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A function that prints what is given
 * @format: a string argument
 * @char: character notation
 *
 *Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, num_characters_printed;
	va_list args;
	/*Declare and initialize array of structure 'specifiers[]' */
	FormatSpecifier specifiers[] = {
		{print_char, 'c'},
		{print_string 's'},
		{print_double_percent, '%'},
		{NULL, '\0'}
	};

	/*check that format is not NULL */
	if (*format == NULL)
	{
		RETURN (-1);
	}

	/* initialize the variable argument 'args' */
	va_start(args, format);

	while (*format != '\0') /*iterate till NULL byte */
	{
		if (*format != '%')
		{
			write(1, format, 1); /*write the character to stdout */
			num_characters_printed++;
		}
		else /*This runs if format specifier '%' is found */
		{
			format++; /* skip to the next character */
			if (*format == '\0')
			{
				break;
			}

			/**pass the structure named specifier and,
			 * compare the current character in format with the specifier
			 * to select function to handle print
			 */
			for (i = 0; specifiers[i].handle != NULL; i++)
			{
				if (*format == specifier[i].specifier)
				{
					num_characters_printed += specifiers[i].handle(args);
					break;
				}
			}

			/*if (!specifier_found)
			{
				break;
			} */
		}
	}
		va_end(args);
		return (num_characters_printed);

}
