#include "main.h"
#include <unistd.h>

/**
 * print_number - Prints an integer.
 * @num: The integer to be printed.
 *
 * Return: The number of digits printed.
 */
int print_number(int num)
{
	int count = 0;
	char buffer[12]; /* Max int: 10 digits + sign + null terminator */

	_itoa(num, buffer);
	count += write(1, buffer, _strlen(buffer));

	return (count);
}

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer.
 * @str: The buffer to store the string representation.
 */
void _itoa(int num, char *str)
{
	int i = 0, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	else if (num == 0)
	{
		str[i++] = '0';
	}
	while (len > 0)
	{
		rem = num % 10;
		str[i + len - 1] = rem + '0';
		num = num / 10;
		len--;
	}
	str[i] = '\0';
}
