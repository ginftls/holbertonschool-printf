#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_integer - Prints an integer using _putchar
 * @n: Integer to be printed
 *
 * Return: Number of digits printed
 */
int print_integer(int n)
{
	int digits = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		digits++;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		print_integer(num / 10);
	}

	_putchar(num % 10 + '0');
	digits++;

	return (digits);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				_putchar(va_arg(args, int));
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					_putchar(*str++);
					printed_chars++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				printed_chars += print_integer(va_arg(args, int));
			}
			else if (*format == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}
