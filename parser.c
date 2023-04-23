#include "main.h"

/**
 * parser - Parses the format string and calls necessary conversion function
 *          depending on the format specifier found.
 *
 * @format: The format string to parse.
 * @funct_list: The list of conversion function pointers.
 * @args: The variable arguments list.
 *
 * Return: The total number of characters printed.
 */

int parser(const char *format, conver_t funct_list[], va_list args)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
	if (format[i] == '%')
	{
	for (j = 0; funct_list[j].sym != NULL; j++)
	{
	if (format[i + 1] == funct_list[j].sym[0])
	{
	r_val = funct_list[j].f(args);
	if (r_val == -1)
	return (-1);
	printed_chars += r_val;
	break;
	}
	}
	if (funct_list[j].sym == NULL && format[i + 1] != ' ')
	{
	if (format[i + 1] != '\0')
	{
	_putchar(format[i]);
	_putchar(format[i + 1]);
	printed_chars = printed_chars + 2;
	}
	else
	return (-1);
	}

	i = i + 1;
	}
	else
	{
	_putchar(format[i]);
	printed_chars++;
	}
	}
	return (printed_chars);
}
