#include "main.h"

/**
 * _our_formats - format selection
 * @format: The formats that are chosen for printing
 * @args: A list of variadic arguments
 *
 * This function iterates over the format string, looking for '%' characters.
 * If a '%' character is found, the function checks to see if the next char
 * is a valid format specifier. If it is, the function calls the corresponding
 * function to print the specifier.
 *
 * Return: The length of the format
 */
int _our_formats(const char *format, va_list args)
{
	int ct = 0; /* The length of the format */
	int i = 0; /* The current index in the format string */

	/* Iterate over the format string */
	while (format && format[i])
	{
		/* If the current character is '%' */
		if (format[i] == '%')
		{
			/* Return -1 if null terminator */
			if (format[i + 1] == '\0')
				return (-1);
			i++;

			/* Skip any whitespace */
			while (format[i] == ' ')
				i++;

			/* Print a % and move on */
			if (format[i] == '%')
				ct += _write(format[i]);

			/* If the next character is not a valid format specifier, print '%' */
			if (_charchecker(format[i]) == 0)
			{
				ct += _write('%');
				ct += _write(format[i]);
			}
			/* Otherwise, call the corresponding function to print the specifier */
			else
				ct += _printspec(format[i], args);
		}
		/* Otherwise, just print the current character */
		else
			ct += _write(format[i]);

		i++;
	}

	return (ct);
}

/**
 * _printspec - Prints a valid specifier
 * @format: The specifier to prints
 * @args: A list of variadic arguments
 *
 * This function takes a format specifier and a list of variadic arguments,
 * and prints the specifier using the corresponding function.
 *
 * Return: The length of the specifier
 */
int _printspec(char format, va_list args)
{
	int i = 0; /* The current index in the specifier array */
	int length = 0; /* The length of the specifier */
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_integer},
		{"i", _print_integer},
		{NULL, NULL}
	};

	/* Iterate over the specifier array */
	while (_types[i].specifier)
	{
		/* If the current specifier matches the format specifier */
		if (*_types[i].specifier == format)
			/* Print the specifier using the corresponding function */
			length = _types[i].f(args);

		i++;
	}

	return (length);
}

/**
 * _charchecker - validate the type
 * @_type: character to be comparate
 *
 * This function takes a character and checks if it is a valid format spec.
 *
 * Return: 1 if the character is equal to a type
 */
int _charchecker(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', '%'};
	int i = 0;

	/* Iterate over the specifier array */
	while (_types[i])
	{
		/* If the current character matches a specifier */
		if (_types[i] == _type)
			return (1);

		i++;
	}

	/* Return 0 if the character is not a specifier */
	return (0);
}
