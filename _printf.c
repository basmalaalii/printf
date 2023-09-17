#include "main.h"

/**
 * handle_format_specifiers - handle format specifiers.
 * @p: Pointer to the current format specifier.
 * @params: parameters structure.
 * @ap: argument list.
 *
 * Return: Number of characters printed.
 */
int handle_format_specifiers(char **p, params_t *params, va_list ap)
{
	char *start;
	int sum = 0;

	start = *p;
	(*p)++;

	while (get_flag(*p, params))
		(*p)++;

	*p = get_width(*p, params, ap);
	*p = get_percision(*p, params, ap);

	if (get_modifier(*p, params))
		(*p)++;

	if (!get_specifier(*p))
	{
		sum += print_from_to(start, *p,
			params->l_modifier || params->h_modifier ? (*p) - 1 : 0);
	}
	else
	{
		sum += get_print_func(*p, ap, params);
	}

	return (sum);
}

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * ... : The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}

		sum += handle_format_specifiers(&p, &params, ap);
	}

	_putchar(BUFFER_FLUSH);
	va_end(ap);

	return (sum);
}
