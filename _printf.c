#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - our printf function
 * @format: printed string with specified formatting
 *
 * Return: number of chars that prints from the string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	len = _our_formats(format, args);
	va_end(args);
	return (len);
}
