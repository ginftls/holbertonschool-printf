#include "main.h"

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
			{
				char c = va_arg(args, int);

				count += _putchar(c);
			}
			else if (*format == 's') /* Handle %s */
			{
				char *str = va_arg(args, char *);
				int i = 0;

				if (!str)
					str = "(null)";
				while (str[i])
				{
					count += _putchar(str[i]);
					i++;
				}
			}
			else if (*format == '%') /* Handle %% */
			{
				count += _putchar('%');
			}
			else /* Handle unknown specifiers */
			{
				count += _putchar('%');
				if (*format)
					count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

