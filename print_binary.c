#include "main.h"
#include <unistd.h>

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @num: The unsigned int to be converted and printed.
 *
 * Return: The number of digits printed.
 */
int print_binary(unsigned int num)
{
	char buffer[32]; /* Max for 32-bit unsigned int */
	int i = 0, count = 0;

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		buffer[i++] = (num % 2) + '0';
		num /= 2;
	}

	for (i = i - 1; i >= 0; i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
