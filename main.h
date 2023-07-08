#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
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
int _badspec(char prev_format, char format, int count);
int _print_integer(va_list args);
int _charchecker(char _type);
#endif
