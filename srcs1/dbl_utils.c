/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:52:31 by jkettani          #+#    #+#             */
/*   Updated: 2020/01/04 22:41:43 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// проверка на бесконечность и NaN (в этом случае возвращаем единицу)
int				is_limit_value(t_dbls *arg_val, t_format *conv_params)
{
	if ((conv_params->len_mod == LEN_MOD_CAP_L
				&& arg_val->ldbl_parts.exponent == 0x7FFF) // экспонента заполнена единицами
		|| (conv_params->len_mod != LEN_MOD_CAP_L
				&& arg_val->dbl_parts.exponent == 0x7FF)) // экспонента заполнена единицами
		return (1);
	else
		return (0);
}

/*
** Handle specific values `nan' and `inf':
**  - `nan': exponent = 0x7FF (double) / exponent = 0x7FFF (long double)
**           and mantissa > 0;
**  - `inf': exponent = 0x7FF (double) / exponent = 0x7FFF (long double)
**           and mantissa = 0;
*/

char			*handle_dbl_limit_values(t_dbls *arg_val, t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
	{
		if (!arg_val->ldbl_parts.mantissa)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
	else
	{
		if (!arg_val->dbl_parts.mantissa)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
}

void			handle_g_conv_spec(int exponent, t_format *conv_params)
{
	conv_params->flags |= FL_TRIM;
	if ((conv_params->flags & FL_PREC) && !conv_params->prec)
		conv_params->prec = 1;
	if ((exponent < conv_params->prec) && (exponent >= -4))
	{
		conv_params->type_char = ft_isupper(conv_params->type_char) ?
			'F' : 'f';
		conv_params->prec = conv_params->prec - 1 - exponent;
	}
	else
	{
		conv_params->type_char = ft_isupper(conv_params->type_char) ?
			'E' : 'e';
		conv_params->prec = conv_params->prec - 1;
	}
}

/*
** Convert the digits extracted to a final value by rounding the number and
** inserting a `.' at the right place.
** If exponent < 0, missing zeros must be added (ex: from 0.0142 only 142 digits
** would be extracted, 2 zeros must be prepended).
*/

char			*handle_dbl_precision(char **digits, int exponent,
										t_format *conv_params)
{
	char		*val_str;
	int			exp_add;

	if (!reformat_digits_buf(digits, &exponent, conv_params))
		return (NULL);
	exp_add = ft_max(ft_tolower(conv_params->type_char) == 'e' ? 0 : exponent,
																			0);
	if (!(val_str = ft_strndup(*digits, exp_add + 1)))
		return (NULL);
	if ((conv_params->flags & FL_HASH) || !((conv_params->flags & FL_PREC)
										&& !(conv_params->prec)))
		if (!ft_strappend(&val_str, ".")) // Туц целая часть
			return (NULL);
	if (conv_params->prec)
		if (!add_dbl_prec(&val_str, *digits + exp_add + 1, conv_params))
			return (NULL);
	if ((conv_params->flags & FL_TRIM) && !(conv_params->flags & FL_HASH)
			&& ft_instr('.', val_str))
		if (!trim_zeros(&val_str, exp_add + 1 + conv_params->prec))
			return (ft_strdel_ret_null(&val_str));
	if (ft_tolower(conv_params->type_char) == 'e')
		if (!add_exponent_sign(&val_str, exponent, conv_params))
			return (NULL);
	return (val_str);
}
