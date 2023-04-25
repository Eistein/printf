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
	int t, j, val, chelsana;

	chelsana = 0;

	for (t = 0; format[t] != '\0'; t++)
	{
	if (format[t] == '%')
	{
	for (j = 0; funct_list[j].sym != NULL; j++)
	{
	if (format[t + 1] == funct_list[j].sym[0])
	{
	val = funct_list[j].f(args);
	if (val == -1)
	return (-1);
	chelsana += val;
	break;
	}
	}
	if (funct_list[j].sym == NULL && format[t + 1] != ' ')
	{
	if (format[t + 1] != '\0')
	{
	_putchar(format[t]);
	_putchar(format[t + 1]);
	chelsana = chelsana + 2;
	}
	else
	return (-1);
	}

	t = t + 1;
	}
	else
	{
	_putchar(format[t]);
	chelsana++;
	}
	}
	return (chelsana);
}
