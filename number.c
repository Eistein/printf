#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_int - Prints integer numbers
 *
 * @args: argument list containing integer to be printed
 *
 * Return: Number of digits printed
 */
int print_int(va_list args)
{
	int digit;

	digit = print_number(args);
	return (digit);

}
