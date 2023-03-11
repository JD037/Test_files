#include "main.h"
#include <stddef.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

/**
 * _printf - custom printf function
 * @format: string to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'r')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += print_reversed(args);
			}
			else
			{
				count += get_print_fn(format[i])(args);
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
