#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_char - Prints a character
  * @args: A list of variadic arguments
  *
  * Return: The length of the character after processing
  */
int _print_char(va_list args)
{
	/* Write the character to the output */
	_write(va_arg(args, int));
	return (1);
}

/**
  * _print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string after processing
  */
int _print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			/* Write each character of the string to the output */
			_write(arg[i]);
			i++;
		}

		return (i);
	}

	/* If the string is NULL, print "(null)" */
	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}
/**
  * _print_integer - Prints an integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string after processing
  */
int _print_integer(va_list args)
{
	int ct = 1, check = 0;
	unsigned int mkunsnd = 0;
	int intprnt[10];
	int i = 0;

	check = va_arg(args, int);

	/* If the integer is negative, print a '-' and make it positive */
	if (check < 0)
	{
		_write('-');
		mkunsnd = -check;
		ct += 1;
	}
	else
	{
		mkunsnd = check;
	}

	/* Count the number of digits in the integer */
	while (check > 9)
	{
		check = check / 10;
		ct++;
	}

	/* Store each digit of the integer in an array */
	while (mkunsnd > 0)
	{
		intprnt[i] = mkunsnd % 10;
		mkunsnd /= 10;
		i++;
	}

	/* Print the integer */
	for (i--; i >= 0; i--)
	{
		_write(intprnt[i] + '0');
	}

	return (ct);
}
