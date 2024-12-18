#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	/* Test character specifier */
	printf("Character Test:\n");
	_printf("Character: %c\n", 'H');
	printf("Character: %c\n", 'H');

	/* Test string specifier */
	printf("\nString Test:\n");
	_printf("String: %s\n", "Hello, World!");
	printf("String: %s\n", "Hello, World!");

	/* Test percent specifier */
	printf("\nPercent Test:\n");
	_printf("Percent: %%\n");
	printf("Percent: %%\n");

	/* Test integer specifiers */
	printf("\nInteger Tests:\n");
	_printf("Positive Integer: %d\n", 42);
	printf("Positive Integer: %d\n", 42);

	_printf("Negative Integer: %i\n", -123);
	printf("Negative Integer: %i\n", -123);

	_printf("Zero: %d\n", 0);
	printf("Zero: %d\n", 0);

	/* Test length comparison */
	len = _printf("Length Test: %d\n", 1024);
	len2 = printf("Length Test: %d\n", 1024);

	/* Print length comparison */
	_printf("Our _printf length: %d\n", len);
	printf("Standard printf length: %d\n", len2);

	/* Test NULL string */
	_printf("Null string test: %s\n", NULL);

	/* Mixed specifiers test */
	_printf("Mixed: char %c, string %s, int %d\n", 'A', "test", 42);

	return (0);
}
