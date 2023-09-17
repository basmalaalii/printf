#include "main.h"

/**
 * get_percision - Extracts the precision value from a format string.
 * @p: The current position in the format string.
 * @params: A structure to store the extracted precisios.
 * @ap: List of arguments.
 *
 * Return: A pointer to the position in the format string after precision.
 */
char *get_percision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->percision = d;
	return (p);
}
