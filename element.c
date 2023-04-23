#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_number - Prints integer numbers
 *
 * @args: argument list containing integer to be printed
 *
 * Return: Number of digits printed
 */
int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);

	check = 1;
	len = 0;
	if (n < 0)
	{
	len += _putchar('-');
	num = n * -1;
	}
	else
	num = n;
	for (; num / check > 9; )
	check *= 10;
	for (; check != 0; )
	{
	len += _putchar('0' + num / check);
	num %= check;
	check /= 10;
	}
	return (len);
}
/**
 * print_unsgined_number - Prints unsigned integer numbers
 *
 * @n: Unsigned integer to be printed
 *
 * Return: Number of digits printed
 */
int print_unsgined_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;
	num = n;
	for (; num / check > 9; )
	check *= 10;
	for (; check != 0; )
	{
	len += _putchar('0' + num / check);
	num %= check;
	check /= 10;
	}
	return (len);
}
/**
 * p_char - Prints a character
 *
 * @args: argument list containing character to be printed
 *
 * Return: Number of characters printed
 */
int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);

	_putchar(value);

	return (1);
}
/**
 * p_string - Prints a string
 *
 * @args: argument list containing string to be printed
 *
 * Return: Number of characters printed
 */
int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);

	if (s == NULL)
	s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	_putchar(s[i]);
	return (i);
}
/**
 * p_percent - Prints a percent sign
 *
 * @args: Unused argument list
 *
 * Return: Number of characters printed
 */
int p_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
