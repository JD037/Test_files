#include "main.h"

/**
 * print_char - Prints a character
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list list)
{
	char c = va_arg(list, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - Prints a string
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list list)
{
	char *str = va_arg(list, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_int - Prints an integer
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_int(va_list list)
{
	int num = va_arg(list, int);
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	else if (num < 0)
	{
		_putchar('-');
		i++;
		num = -num;
	}

	if (num / 10)
		i += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	i++;

	return (i);
}

/**
 * print_binary - Prints a binary number
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_binary(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	else
		i += print_binary_helper(num);

	return (i);
}

/**
 * print_hex - Prints a hexadecimal number
 * @list: List of arguments
 *
 * Return: Number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		i++;
	}
	else
		i += print_hex_helper(num);

	return (i);
}
