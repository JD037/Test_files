#include "main.h"
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

/**
 * struct print_ops - struct for printing operations
 *
 * @op: the operator
 * @func: the function associated
 *
 * Description: struct that stores a character operator and a function pointer
 * to the corresponding function that handles that operator.
 */
typedef struct print_ops
{
	char op;
	int (*func)(va_list);
} print_op_t;

int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);

/**
 * _printf - prints output according to a format.
 *
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed (excluding null byte used to end output
 * to strings), or -1 if error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, count = 0;
	print_op_t ops[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{0, NULL}
	};

	if (!format)
		return (-1);

	va_start(args, format);

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (ops[j].op)
			{
				if (format[i + 1] == ops[j].op)
				{
					count += ops[j].func(args);
					i++;
					break;
				}
				j++;
			}
			if (!ops[j].op)
			{
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * print_char - prints a character
 *
 * @args: va_list that contains a single argument of type char
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_str - prints a string
 *
 * @args: va_list that contains a single argument of type char *
 *
 * Return: number of characters printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * print_percent - prints a percent character
 *
 * @args: va_list that contains no arguments
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

