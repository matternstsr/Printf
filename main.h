#ifndef MAIN_H
#define MAIN_H

void print_char(va_list args);
void print_string(va_list args);
void print_percent(va_list args __attribute__((unused)));
void print_int(va_list args);
int _putchar(char c);
void _puts(char *str);
void print_number(int n);
int _printf(const char *format, ...);

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
