#include "main.h"

/**
 * print_int_helper - recursively prints an integer
 * @num: the integer to print
 *
 * Return: the number of digits printed
 */
int print_int_helper(int num)
{
	int digits = 0;

	if (num / 10)
		digits += print_int_helper(num / 10);

	return (_putchar(num % 10 + '0') + digits);
}

/**
 * print_octal_helper - recursively prints an integer in octal
 * @num: the integer to print
 *
 * Return: the number of digits printed
 */
int print_octal_helper(unsigned int num)
{
	int digits = 0;

	if (num / 8)
		digits += print_octal_helper(num / 8);

	return (_putchar(num % 8 + '0') + digits);
}

/**
 * print_hex_helper - recursively prints an integer in hexadecimal
 * @num: the integer to print
 * @type: the letter case of the hexadecimal digits ('x' or 'X')
 *
 * Return: the number of digits printed
 */
int print_hex_helper(unsigned int num, char type)
{
	int digits = 0;

	if (num / 16)
		digits += print_hex_helper(num / 16, type);

	if (num % 16 < 10)
		digits += _putchar(num % 16 + '0');
	else
		digits += _putchar(num % 16 + type - 33);

	return (digits);
}

/**
 * print_binary_helper - recursively prints an integer in binary
 * @num: the integer to print
 *
 * Return: the number of digits printed
 */
int print_binary_helper(unsigned int num)
{
	int digits = 0;

	if (num / 2)
		digits += print_binary_helper(num / 2);

	return (_putchar(num % 2 + '0') + digits);
}
