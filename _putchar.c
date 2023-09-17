#include "main.h"

/**
 * _putchar - outputs a character or flushes the buffer
 * @c: character to print or BUFFER_FLUSH to flush the buffer
 *
 * Return: 1 on success, otherwise nothing
 */
int _putchar(int c)
{
	static int i;
	static char buffer[OUTPUT_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= OUTPUT_BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != BUFFER_FLUSH)
	{
		buffer[i++] = c;
		return (1);
	}
	return (unsigned char)c;
}
