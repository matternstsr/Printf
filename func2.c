#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: The string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * print_number - prints an integer
 * @n: The integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	int i, size;
	unsigned int num, num_temp, dig, div;

	num = n;
	size = 0;
	div = 1;

	/* Check if n is 0, and end */
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* If n is negative, make it positive and print a '-' sign */
	if (n < 0)
	{
		num = n * -1;
		size++;
		_putchar('-');
	}

	/* Calculate the number of digits in n */
	num_temp = num;
	while (num_temp != 0)
	{
		num_temp /= 10;
		size++;
		div *= 10;
	}
	div /= 10;

	/* Print each digit of n */
	for (i = 1; i <= size; i++)
	{
		dig = num / div;
		if (num > 9)
			num %= div;
		div /= 10;
		_putchar(dig + '0');
	}
}
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, count;
	f_type formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{0, NULL}
	};

	va_start(args, format);
	count = 0;

	/* Loop through each character in the format string */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* If the char is '%', check next char for a format specifier */
		if (format[i] == '%')
		{
			i++;
			for (j = 0; formats[j].type != 0; j++)
			{
				if (format[i] == formats[j].type)
				{
					formats[j].f(args);
					count++;
					break;
				}
			}
		}
		else /* If the current character is not a '%', just print it */
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}
