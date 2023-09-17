#include "main.h"

/**
 * init_params - initializes a params_t structure to its default values.
 * @params: pointer to a params_t structure to initialize.
 * @ap: variable argument list, currently unused.
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->percision = UINT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;

	(void) ap;
}
