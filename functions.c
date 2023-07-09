#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * _print_char - Prints a character
  * @args: A list of variadic arguments
  *
  * This function prints a character.
  *
  * Return: The length of the character after processing
  */
int _print_char(va_list args)
{
	/* Gets the character from the va_list. */
	int c = va_arg(args, int);

	/* Writes the character to stdout. */
	_write(c);

	/* Returns the length of the character. */
	return (1);
}

/**
  * _print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * This function prints a string.
  *
  * Return: The length of the string after processing
  */
int _print_string(va_list args)
{
	/* Gets the string from the va_list. */
	char *arg = va_arg(args, char *);
	int i = 0;

	/* Checks if the string is NULL. */
	if (arg != NULL)
	{
		/* Iterates over the string, writing each character to stdout. */
		while (arg[i])
		{
			/* Writes the character to stdout. */
			_write(arg[i]);
			/* Increments the counter. */
			i++;
		}

		/* Returns the length of the string. */
		return (i);
	}

	/* If the string is NULL, prints "(null)" to stdout. */
	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');

	/* Returns the length of the string, which is 6. */
	return (6);
}

/**
  * _print_integer - Prints a integer
  * @args: A list of variadic arguments
  *
  * This function prints an integer.
  *
  * Return: The length of the string after processing
  */
int _print_integer(va_list args)
{
        int character_count = 1, unsigned_integer = 0;
        unsigned int temp_integer = 0;

        /* Gets the integer from the va_list. */
        temp_integer = va_arg(args, int);
        unsigned_integer = temp_integer;

        /* Temp_integers if the integer is negative. */
        if (unsigned_integer < 0)
        {
                /* Prints a '-' characharacter_counter to stdout. */
                _write('-');
                /* Converts the integer to positive. */
                unsigned_integer = unsigned_integer * -1;
                temp_integer = unsigned_integer;
                /* Updates the counter. */
                character_count++;
        }

        /* Iterates while the integer is greater than 9. */
        while (temp_integer > 9)
        {
                /* Divides the integer by 10. */
                temp_integer = temp_integer / 10;
                /* Increments the counter. */
                character_count++;
        }

        /* Recursively calls the funcharacter_countion to print the integer. */
        _integer_printer(unsigned_integer);

        /* Returns the length of the integer. */
        return (character_count);
}
/**
  * _integer_printer - Prints an integer recursively
  * @a: int brought in for print
  *
  * This function prints an integer recursively.
  *
  * Return: Nothing
  */
void _integer_printer(int a)
{
	unsigned int intprnt;

	/* Gets the integer. */
	intprnt = a;

	/* Checks if the integer is greater than 9. */
	if (intprnt / 10)
	{
		/* Recursively calls the function to print the integer. */
		_integer_printer(intprnt / 10);
	}

	/* Prints the last digit of the integer. */
	_write(intprnt % 10 + '0');
}
