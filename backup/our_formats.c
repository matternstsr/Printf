#include "main.h"
#include <stdlib.h>

/**
  * _our_formats - format selection
  * @format: The formats that are chosen for printing
  * @args: A list of variadic arguments
  * Return: The length of the format
  */
int _our_formats(const char *format, va_list args)
{
	int ct = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				ct += _write(format[i]);

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
  * _printspec - Prints a valid specifier
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  * Return: The length of the specifier
  */
int _printspec(char format, va_list args)
{
	int i  = 0, length = 0;
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_integer},
		{"i", _print_integer},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			length = _types[i].f(args);

		i++;
	}

	return (length);
}

/**
  * _badspec - Prints a bad specifier
  * @prev_format: The previous specifier of actual specifier
  * @format: The selected specifider to print
  * @ct: what the count is before prints bad specs.
  * Return: what the count is after prints invalid specifiers
  */
int _badspec(char prev_format, char format, int ct)
{
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
  * _charchecker - validate the type
  * @_type: character to be comparate
  * Return: 1 if the character is equal to a type
  */
int _charchecker(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
