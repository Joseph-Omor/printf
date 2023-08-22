#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_double_percent(va_list args);
int _printf(const char *format, ...);

/**
 * struct specifiers - A structure with two members.
 * @handle: a function pointer to handle print for specifier
 * @specifier: a function pointer to handle print for specifier
 */
typedef struct specifiers
{
	int (*handle)(va_list);
	char specifier;
} FormatSpecifier;



#endif /* MAIN_H */
