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
	char *sarg = va_arg(args, char *);
	int i = 0;

	if (sarg != NULL)
	{
		while (sarg[i])
		{
			_write(sarg[i]);
			i++;
		}

		return (i);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
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


/**
 * _write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
