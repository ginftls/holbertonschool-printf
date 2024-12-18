#include "main.h"
#include <stdarg.h>

/**
 * print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);
	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * _printf - Custom implementation of printf
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c') /* Handle %c */
				count += _putchar(va_arg(args, int));
			else if (*format == 's') /* Handle %s */
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}
			else if (*format == 'd' || *format == 'i') /* Handle %d and %i */
				count += print_number(va_arg(args, int));
			else if (*format == '%') /* Handle %% */
				count += _putchar('%');
			else /* Handle unknown specifiers */
			{
				count += _putchar('%');
				if (*format)
					count += _putchar(*format);
			}
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}

