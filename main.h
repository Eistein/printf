#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>


struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;


int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int print_char(va_list);
int print_str(va_list args);
int print_percent(va_list);
int print_unsigned(unsigned int n);
int print_number(va_list);
int print_int(va_list);

#endif
