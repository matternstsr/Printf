#include "main.h"
/**
 * _our_formats - Prints formatted output
 * @format: The format string
 * @args: A list of variadic arguments
 *
 * This function prints formatted output.
 *
 * The format string can contain format specifiers, which are replaced
 * with the corresponding values from the variadic argument list.
 *
 * Return: The length of the string after processing
 */
int _our_formats(const char *format, va_list args)
{
	int ct = 0;
	int i = 0;
	int j;
	spc_dt _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_integer},
		{"i", _print_integer},
		{NULL, NULL}
	};

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
			else
			{
				j = 0;
				while (_types[j].specifier)
				{
					if (*_types[j].specifier == format[i])
						break;
					j++;
				}
				if (_types[j].specifier)
					ct += _types[j].f(args);
				else
				{
					ct += _write('%');
					ct += _write(format[i]);
				}
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
