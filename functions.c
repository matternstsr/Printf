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
  * _print_integer - Prints a integer
  * @args: A list of variadic arguments
  *
  * Return: The length of the string after processing
  */
int _print_integer(va_list args)
{
	int ct = 1, mkunsnd = 0;
	unsigned int check = 0;

	check = va_arg(args, int);
	mkunsnd = check;

	/* If the integer is negative, print a '-' and make it positive */
	if (mkunsnd < 0)
	{
		_write('-');
		mkunsnd = mkunsnd * -1;
		check = mkunsnd;
		ct += 1;
	}

	/* Count the number of digits in the integer */
	while (check > 9)
	{
		check = check / 10;
		ct++;
	}

	/* Print the integer */
	_integer_printer(mkunsnd);

	return (ct);
}

/**
  * _integer_printer - Prints an integer
  * @a: int brought in for print
  *
  * Return: Nothing
  */
void _integer_printer(int a)
{
	unsigned int intprnt;

	intprnt = a;

	/* Recursively print each digit of the integer */
	if (intprnt / 10)
	_integer_printer(intprnt / 10);
	/* Write the current digit to the output */
	_write(intprnt % 10 + '0');
}
