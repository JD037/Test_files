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
		{'x', print_hex},/* lowercase hex */
		{'X', print_HEX},/* uppercase hex */
		{'o', print_octal},
		{'b', print_binary},
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

/**
 * print_percent - prints a percent character
 * @args: the va_list containing the percent character
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void) args;
	return (_putchar('%'));
}

/**
 * print_HEX - prints an unsigned int in uppercase hexadecimal
 * @args: the va_list containing the unsigned int to print
 *
 * Return: number of characters printed
 */
int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;

	digits += print_hex_helper(num);

	return (digits);
}

/**
 * print_pointer - prints a pointer address
 * @args: the va_list containing the pointer to print
 *
 * Return: number of characters printed
 */
int print_pointer(va_list args)
{
	void *p = va_arg(args, void *);

	if (!p)
		return (_printf("(nil)"));

	return (_printf("0x%lx", (unsigned long)p));
}

/**
 * print_reversed - prints a string in reverse
 * @args: the va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_reversed(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (!s)
		return (_printf("(null)"));

	len = strlen(s);

	for (len--; len >= 0; len--)
		_putchar(s[len]);
	return (strlen(s));
}
