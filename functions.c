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
			_write(arg[i]);
			i++;
		}

		return (i);
	}

	_write(')');
	_write('l');
	_write('l');
	_write('u');
	_write('n');
	_write('(');
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
	if (mkunsnd < 0)
	{
		_write('-');
		mkunsnd = mkunsnd * -1;
		check = mkunsnd;
		ct += 1;
	}
	while (check > 9)
	{
		check = check / 10;
		ct++;
	}

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
	if (intprnt / 10)
		_integer_printer(intprnt / 10);
	_write(intprnt % 10 + '0');
}
