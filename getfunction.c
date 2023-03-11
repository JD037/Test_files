#include "main.h"

/**
 * get_print_fn - get function to print specifier
 * @c: specifier character
 *
 * Return: pointer to function that prints specifier
 */
int (*get_print_fn(const char c))(va_list)
{
	int i = 0;
	print_fn fns[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'%', print_percent},
		{'x', print_hex},
		{'X', print_HEX},
		{'o', print_octal},
		{'u', print_unsigned},
		{'p', print_pointer},
		{'r', print_reversed},
		{'\0', NULL}
	};

	while (fns[i].specifier != '\0')
	{
		if (fns[i].specifier == c)
			return (fns[i].fn);
		i++;
	}

	return (NULL);
}
