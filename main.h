#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/** struct print_fn - struct containing a function and corresponding specifier
 * @specifier: the specifier character
 * @fn: the function that prints the specifier
 */
typedef struct print_fn
{
	char specifier;
	int (*fn)(va_list);
} print_fn;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_octal(va_list args);
int print_pointer(va_list args);
int print_percent(va_list args);
int print_reversed(va_list args);
int (*get_print_fn(const char c))(va_list);

#endif /* MAIN_H */
