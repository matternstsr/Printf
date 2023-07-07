#include "main.h"
#include <stdlib.h>

/**
 * _our_formats - Selects the format for printing
 * @format: The format string containing the specifiers to print
 * @args: A list of variadic arguments to print
 *
 * Return: The total number of characters printed
 */
int _our_formats(const char *format, va_list args)
{
	int ct = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			/* Check if the next character after '%' is '\0' */
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			/* Skip any spaces after the '%' character */
			while (format[i] == ' ')
				i++;

			/* Check if the current character is '%' */
			if (format[i] == '%')
				ct += _write(format[i]);

			/* Check if the current character is a valid specifier */
			if (_charchecker(format[i]) == 0)
			{
				ct = _badspec(format[i - 1], format[i], ct);
			}
			else
			{
				ct += _printspec(format[i], args);
			}
		}
		else
		{
			ct += _write(format[i]);
		}

		i++;
	}

	return (ct);
}

/**
 * _printspec - Prints a valid specifier to the output
 * @format: The specifier to print
 * @args: A list of variadic arguments containing the value to print
 *
 * Return: The number of characters printed
 */
int _printspec(char format, va_list args)
{
	int i = 0, length = 0;
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_integer},
		{"i", _print_integer},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		/* Check if the current specifier matches the format */
		/* If it does, call the corresponding function to print it */
		/* and update the length variable with the number of characters printed */

		if (*_types[i].specifier == format)
			length = _types[i].f(args);

		i++;
	}

	return (length);
}

/**
 * _badspec - Prints an invalid specifier to the output
 * @prev_format: The previous character before the invalid specifier
 * @format: The invalid specifier to print
 * @ct: The current count of characters printed before this function call
 *
 * Return: The new count of characters printed after this function call
 */
int _badspec(char prev_format, char format, int ct)
{
	/* Print a '%' character followed by the invalid specifier */
	ct += _write('%');

	if (prev_format == ' ')
	{
		ct += _write(' ');
		ct += _write(format);
	}
	else
	{
		ct += _write(format);
	}

	return (ct);
}

/**
 * _charchecker - Checks if a character is a valid specifier
 * @_type: The character to check
 *
 * Return: 1 if the character is a valid specifier, otherwise returns 0
 */
int _charchecker(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (_types[i])
	{
		/* Check if the character matches any of the valid specifiers */
		if (_types[i] == _type)
			return (1);

		i++;
	}

	return (0);
}
