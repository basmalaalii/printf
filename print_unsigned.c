#include "main.h"
#include <unistd.h>

/**
 * print_unsigned - Converts and prints an unsigned int in specified base.
 * @num: The unsigned int to be converted and printed.
 * @base: The base to convert to (8 for octal, 10 for decimal, 16 for hex).
 * @uppercase: Whether to print hexadecimal digits in uppercase.
 *
 * Return: The number of digits printed.
 */
int print_unsigned(unsigned int num, int base, int uppercase)
{
	char buffer[32];
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	int i = 0, count = 0;

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		buffer[i++] = digits[num % base];
		num /= base;
	}

	for (i = i - 1; i >= 0; i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
