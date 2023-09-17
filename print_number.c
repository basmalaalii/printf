#include "main.h"

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to check.
 * Return: 1 if digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - Prints a number with formatting.
 * @str: The number string.
 * @params: Parameters for printing.
 * Return: The number of characters printed.
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int negative = (!params->unsign && *str == '-');

	if (!params->percision && *str == '0' && !str[1])
		str = "";
	if (negative)
		str++, i--;
	if (params->percision != UINT_MAX)
		while (i++ < params->percision)
			*--str = '0';
	if (negative)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - Prints a number with right alignment.
 * @str: The number string.
 * @params: Parameters for printing.
 * Return: The number of characters printed.
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, negative, negative2, i = _strlen(str);
	char padding_char = params->zero_flag && !params->minus_flag ? '0' : ' ';

	negative = negative2 = (!params->unsign && *str == '-');
	if (negative && padding_char == '0' && !params->minus_flag)
		str++;
	else
		negative = 0;

	if ((params->plus_flag && !negative2) ||
			(!params->plus_flag && params->space_flag && !negative))
		i++;

	if (negative && padding_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !negative2 && padding_char == '0')
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2)
		n += _putchar(' ');

	while (i++ < params->width)
		n += _putchar(padding_char);
	n += _puts(str);

	return (n);
}

/**
 * print_number_left_shift - Prints a number with left alignment.
 * @str: The number string.
 * @params: Parameters for printing.
 * Return: The number of characters printed.
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, negative, negative2, i = _strlen(str);
	char padding_char = ' ';

	negative = negative2 = (!params->unsign && *str == '-');
	if (negative && !params->minus_flag)
		str++;
	else
		negative = 0;

	if (params->plus_flag && !negative2)
		n += _putchar('+'), i++;
	else if (!negative && !params->unsign)
		n += _putchar(' ');

	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(padding_char);

	return (n);
}
