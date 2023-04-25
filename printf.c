#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 *
 * @format: string with format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int chelsana;

	conver_t funct_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	chelsana = parser(format, funct_list, args);
	va_end(args);
	return (chelsana);
}
