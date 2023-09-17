#include "main.h"

/**
 * print_char - Prints a character.
 * @ap: Argument list.
 * @params: Print parameters.
 * Return: Number of characters printed.
 */
int print_char(va_list ap, params_t *params)
{
	char padding_char = ' ';
	unsigned int padding = 1, sum = 0;
	char ch = (char) va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);

	while (padding++ < params->width)
		sum += _putchar(padding_char);

	if (!params->minus_flag)
		sum += _putchar(ch);

	return (sum);
}

/**
 * print_int - Prints an integer.
 * @ap: Argument list.
 * @params: Print parameters.
 * Return: Number of characters printed.
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);

	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - Prints a string.
 * @ap: Argument list.
 * @params: Print parameters.
 * Return: Number of characters printed.
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char padding_char = ' ';
	unsigned int sum = 0, j, padding;

	if (!str)
		str = NULL_STRING;

	j = padding = _strlen(str);
	if (params->percision < padding)
		j = padding = params->percision;

	if (params->minus_flag)
	{
		for (unsigned int i = 0; i < padding; i++)
			sum += _putchar(*str++);
	}

	while (j++ < params->width)
		sum += _putchar(padding_char);

	if (!params->minus_flag)
	{
		for (unsigned int i = 0; i < padding; i++)
			sum += _putchar(*str++);
	}

	return (sum);
}

/**
 * print_percent - Prints a percent sign.
 * @ap: Argument list.
 * @params: Print parameters.
 * Return: Number of characters printed.
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - Prints a string with non-printable characters in hex.
 * @ap: Argument list.
 * @params: Print parameters.
 * Return: Number of characters printed.
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if (!str)
		return (_puts(NULL_STRING));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
