#ifndef MAIN_H
#define MAIN_H

void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args __attribute__((unused)));
void print_int(va_list args);
int _putchar(char c);
void _puts(char *str);
int _printf(const char *format, ...);
void _recursion_integer(int a);
int _print_a_integer(va_list args);
int _write(char c);

/**
 * struct format_type - Struct op
 *
 * @type: The format type
 * @f: The function associated with the format type
 */
typedef struct format_type
{
	char type;
	void (*f)(va_list);
} f_type;

#endif
