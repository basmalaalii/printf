#include "main.h"

/**
 * get_specifier - Matches a format specifier to its corresponding function.
 * @s: format string
 *
 * Return: Pointer to the corresponding function, or NULL if none found.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"hex", print_hex},
		{"HEX", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].f);
		i++;
	}

	return (NULL);
}

/**
 * get_print_func - Retrieves a function pointer based on the given specifier.
 * @s: The format string.
 * @ap: Argument list containing values for the format specifiers.
 * @params: Structure containing parameters for formatting.
 *
 * Return: The number of characters printed.
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *params) = get_specifier(s);

	if (f)
		return (f(ap, params));

	return (0);
}

/**
 * get_flag - Determines the flag of the format specifier.
 * @s: Pointer to the current character being evaluated.
 * @params: Structure containing parameters for formatting.
 *
 * Return: An integer indicating if a flag is set.
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = params->plus_flag = 1;
		break;
	case ' ':
		i = params->space_flag = 1;
		break;
	case '#':
		i = params->hashtag_flag = 1;
		break;
	case '-':
		i = params->minus_flag = 1;
		break;
	case '0':
		i = params->zero_flag = 1;
		break;
	}

	return (i);
}

/**
 * get_modifier - Determines the modifier of the format specifier.
 * @s: Pointer to the current character being evaluated.
 * @params: Structure containing parameters for formatting.
 *
 * Return: An integer indicating if a modifier is set.
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}

	return (i);
}

/**
 * get_width - Retrieves the width for formatting from the format string.
 * @s: Pointer to the current character being evaluated.
 * @params: Structure containing parameters for formatting.
 * @ap: Argument list containing values for the format specifiers.
 *
 * Return: Updated pointer after fetching width.
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}

	params->width = d;

	return (s);
}
