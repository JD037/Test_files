#include "main.h"

/**
 * print_octal - Prints an octal number
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	else
		i += print_octal_helper(num);

	return (i);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	else if (num / 10)
		i += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	i++;

	return (i);
}
