#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_char - prints a char
 * @args: The arguments list
 *
 * Return: void
 */
void print_char(va_list args)
{
	_putchar(va_arg(args, int));
}

/**
 * print_string - prints a string
 * @args: The arguments list
 *
 * Return: void
 */
void print_string(va_list args)
{
	_puts(va_arg(args, char *));
}

/**
 * print_percent - prints a percent sign
 * @args: The arguments list (unused)
 *
 * Return: void
 */
void print_percent(va_list args __attribute__((unused)))
{
	_putchar('%');
}

/**
 * print_int - prints an integer
 * @args: The arguments list
 *
 * Return: void
 */
void print_int(va_list args)
{
	print_number(va_arg(args, int));
}
