/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_spec_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:31:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 15:32:38 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Update the `flags' member in the `t_format' structure.
*/

static void			save_flag(const char c, t_format *conv_params)
{
	if (c == MINUS)
		conv_params->flags |= FL_MINUS;
	else if (c == PLUS)
		conv_params->flags |= FL_PLUS;
	else if (c == SPACE)
		conv_params->flags |= FL_SPACE;
	else if (c == HASH)
		conv_params->flags |= FL_HASH;
	else if (c == ZERO)
		conv_params->flags |= FL_ZERO;
}

/*
** Update the `len_modif' member value in the `t_format' structure.
*/

static void			save_len_modif(const char *fmt, t_format *conv_params)
{
	if (*fmt == 'h')
		conv_params->len_mod = (*(fmt - 1) == 'h') ? LEN_MOD_HH : LEN_MOD_H;
	else if (*fmt == 'l')
		conv_params->len_mod = (*(fmt - 1) == 'l') ? LEN_MOD_LL : LEN_MOD_L;
	else if (*fmt == 'L')
		conv_params->len_mod = LEN_MOD_CAP_L;
	else if (*fmt == 'j')
		conv_params->len_mod = LEN_MOD_J;
	else if (*fmt == 'z')
		conv_params->len_mod = LEN_MOD_Z;
}

static void			save_type(const char c, t_format *conv_params)
{
	if (c == PERCENT)
		conv_params->flags |= FL_ERR;
	if (c == 'p')
	{
		conv_params->flags |= (FL_HASH | FL_POINT);
		conv_params->len_mod = LEN_MOD_L;
		conv_params->type_char = 'x';
	}
	else if (c == 'D' || c == 'O' || c == 'U')
	{
		conv_params->len_mod = LEN_MOD_L;
		conv_params->type_char = ft_tolower(c);
	}
	else
		conv_params->type_char = c;
	conv_params->is_signed = (ft_instr(conv_params->type_char, SIGNED_TYPES)) ?
															SIGNED : UNSIGNED;
}

/*
** Parse a conversion specification (string portion starting after the `%'
** character and ending with a conversion specifier) and extract the
** different parameters (flags, width, precision, length, type).
*/

const char			*parse_conv_spec(const char *fmt, t_format *conv_params,
														va_list args)
{
	while (*fmt && !ft_instr(*fmt, TYPES))
	{
		if (ft_isdigit(*fmt) && *fmt != ZERO)
			fmt = save_value_skip_digits(fmt, conv_params) - 1;
		else if (*fmt == ASTERISK)
			save_width(conv_params, args);
		else if (*fmt == DOT)
			fmt = save_prec(fmt, conv_params, args);
		else if (ft_instr(*fmt, FLAGS))
			save_flag(*fmt, conv_params);
		else if (ft_instr(*fmt, LEN_MODIFS))
			save_len_modif(fmt, conv_params);
		else
		{
			conv_params->flags |= FL_ERR;
			break ;
		}
		++fmt;
	}
	if (*fmt)
		save_type(*fmt, conv_params);
	return ((*fmt) ? ++fmt : fmt);
}
