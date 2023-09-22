#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to print formatted output.
 * @format: Format string containing the specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%' &&
				(*(ptr + 1) == 'c' || *(ptr + 1) == 's' || *(ptr + 1) == '%'))
		{
			ptr++;
			switch (*ptr)
			{
			case 'c':
				count += write(1, &(char){va_arg(args, int)}, 1);
				break;
			case 's':
			{
				char *str = va_arg(args, char *);

				str = (str == NULL) ? "(null)" : str;

				count += write(1, str, _strlen(str));
				break;
			}
			case '%':
				count += write(1, "%", 1);
				break;
			}
		}
		else if (*ptr == '%')
			continue;
		else
			count += write(1, ptr, 1);
	}
	va_end(args);
	return (count);
}

/**
 * _strlen - Computes the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}
