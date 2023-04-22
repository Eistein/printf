#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void write_buffer(char buffer[], int *buff_index);

/**
 * my_printf - Printf function
 * @format: format string.
 * Return: number of printed characters.
 */
int my_printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				write_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			write_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	write_buffer(buffer, &buff_index);

	va_end(ap);

	return (printed_chars);
}

/**
 * write_buffer - Writes the contents of the buffer to standard output stream
 * @buffer: Array of chars.
 * @buff_index: Index at which to add next char, represents the length.
 */
void write_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
