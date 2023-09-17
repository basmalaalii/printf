#include "main.h"

/**
 * _puts - prints a string and returns its length
 * @str: string to print
 *
 * Return: length of the printed string
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
	{
		_putchar(*str++);
	}

	return (str - a);
}
