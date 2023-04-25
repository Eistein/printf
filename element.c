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
	int test;
	int len;
	unsigned int a;

	n = va_arg(args, int);

	test = 1;
	len = 0;
	if (n < 0)
	{
	len += _putchar('-');
	a = n * -1;
	}
	else
	a = n;
	for (; a / test > 9; )
	test *= 10;
	for (; test != 0; )
	{
	len += _putchar('0' + a / test);
	a %= test;
	test /= 10;
	}
	return (len);
}
/**
 * print_unsigned - Prints unsigned integer numbers
 *
 * @n: Unsigned integer to be printed
 *
 * Return: Number of digits printed
 */
int print_unsigned(unsigned int n)
{
	int test;
	int len;
	unsigned int a;

	test = 1;
	len = 0;
	a = n;
	for (; a / test > 9; )
	test *= 10;
	for (; test != 0; )
	{
	len += _putchar('0' + a / test);
	a %= test;
	test /= 10;
	}
	return (len);
}
/**
 * print_char - Prints a character
 *
 * @args: argument list containing character to be printed
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char val;

	val = va_arg(args, int);

	_putchar(val);

	return (1);
}
/**
 * print_str - Prints a string
 *
 * @args: argument list containing string to be printed
 *
 * Return: Number of characters printed
 */
int print_str(va_list args)
{
	int j;
	const char *ptr;

	ptr = va_arg(args, const char *);

	if (ptr == NULL)
	ptr = "(null)";

	for (j = 0; ptr[j] != '\0'; j++)
	_putchar(ptr[j]);
	return (j);
}
/**
 * print_percent - Prints a percent sign
 *
 * @args: Unused argument list
 *
 * Return: Number of characters printed
 */
int print_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
