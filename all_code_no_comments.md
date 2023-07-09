OUR CODE:

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

---------------------------------------------------------------------------


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
                ct += _write('%');
                ct += _write(format[i]);
            }
            else
                ct += _printspec(format[i], args);
        }
        else
            ct += _write(format[i]);

        i++;
    }

    return (ct);
}

---------------------------------------------------------------------------


int _printspec(char format, va_list args)
{
    int i = 0;
    int length = 0;
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

---------------------------------------------------------------------------


int _charchecker(char _type)
{
    char _types[] = {'c', 's', 'd', 'i', '%'};
    int i = 0;

    while (_types[i])
    {
        if (_types[i] == _type)
            return (1);

        i++;
    }

    return (0);
}


--------------------------------------------------------------------------------------------------

#include <unistd.h>

int _write(char c)
{
    return (write(1, &c, 1));
}

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int _print_char(va_list args)
{
    int c = va_arg(args, int);

    _write(c);

    return (1);
}

---------------------------------------------------------------------------


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

    _write('(');
    _write('n');
    _write('u');
    _write('l');
    _write('l');
    _write(')');

    return (6);
}

---------------------------------------------------------------------------

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
        ct++;
    }

    while (check > 9)
    {
        check = check / 10;
        ct++;
    }

    _integer_printer(mkunsnd);

    return (ct);
}

void _integer_printer(int a)
{
    unsigned int intprnt;

    intprnt = a;

    if (intprnt / 10)
        _integer_printer(intprnt / 10);

  	_write(intprnt % 10 + '0');
}
---------------------------------------------------------------------------


#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <limits.h>
#include <stddef.h>


/**
  * struct specifiers - Struct prototype specifiers
  * @specifier: The converting specifier
  * @f: pointer to the needed function
  */
typedef struct specifiers
{
       	char *specifier;
       	int (*f)(va_list args);
} spc_dt;
int _write(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);
int _our_formats(const char *format, va_list args);
int _printspec(char format, va_list args);
int _print_integer(va_list args);
void _integer_printer(int a);
int _charchecker(char _type);
#endif


----------------------------------------------------------------------------


# Our amazing printf() function

**_printf** - formatted output conversion

**#include "main.h"** **int _printf(const char** *format* **, ...);**

*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

**Description**

The **_printf()** function produce output according to a *format* as described below. Also, write output to *stdout*, the standard output stream.

The **_printf()** function write the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of ***stdarg(3)\*** are converted for output.

*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

**Conversion specifiers**

A character that specifies the type of conversion to be applied. The conversion specifiers and their meaning are:

- **d, i**: The int\ argument should be signed decimal notation, and the resulting number is written.
- **c**: The int\ argument is converted to a char, and the resulting character is written.
- **s**: The const char\ argument is expected to be a pointer to an array of character type (pointer to a string).     Characters from the array are written up to (but not including) a terminating null byte ('\0').
- **%**: A '**%**' is written. No argument is converted. The complete conversion specification is '**%%**'.

*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

**Formatting of the format string**

The format string is a character string, beginning and ending inits initial shift state, if any. The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character % and ends with conversion specifier.

*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

**About our chosen functions**

* **int _write(char c)**
  This function gets a char parameter and writes the parameter to the stdout, the standard output stream.

* ***int _print_char (va_list args)***
  This function gets a variadic arguments list, traverse the list, prints each character of char type and returns the length of the character.

* ***int _print_string (va_list args)***
This function gets a variadic arguments list, traverse the list, prints each string and returns the length of the string.

* **int _print_integer (va_list args)**
This function gets a variadic arguments list, traverse the list, prints each number of int type and returns the length of the integer.

* **int _our_formats (const char \*format, va_list args)**
This function gets a format to be printed and a variadic arguments list, next to check if the format is valid or invalid and according with the verification the resulting output is written to the standard output stream and returns the format length.

* **int _printspec (char format, va_list args):**
This function gets a format valid to be printed and a variadic arguments list to find the format in the list and selects the appropriate function to execute and writes the format to the standard output stream and returns the length of the valid format.

* **int _badspec (char prev_format, char format, int count)**
This function gets the previous format of the current format, the actual format and the current count of printed characters. Next, the invalid format is written to the standard output stream and returns the length of the invalid format.

* **void _integer_printer(int a)**
This function gets an integer and prints the last digit of the number as recursion is applied.

* **int _charchecker(char _type)**
Gets a type and checks if the passed parameter is present in a structure of valid conversion specifiers. Next, returns if the parameter is valid or invalid.

* **Return Value**
If not errors, the **_printf()** function return the number of characters printed (excluding the null byte used to end output to strings. If an output error is encountered, a negative value is returned.

*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

* **Examples**

_printf("I love holberton"); **// the output will be: I love Holberton**

_printf("%c", 'H'); // **the output will be: H**

_printf("Complete the sentence: Holberton %s rocks.\n", "totally"); **// the output will be: Complete the sentence: Holberton totally rocks.**

_printf("% s", "Holbies"); **// the output will be: Holbies**

_printf("% h"); **// the output will be: % h**

_printf("%!\n"); **// the output will be '%!'**

_printf("%s", "Holberton is awesome"); **// the output will be: Holberton is awesome**

**Created by**

**_printf()** (often confused with printf()) is written and maintained by Matt Ernst and Connor True.



