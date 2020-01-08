/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:15:14 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 15:35:07 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Return a t_ints union with the right member initialized based on the
** value of the `len_mod` member in the t_format structure.
*/

static t_ints	convert_imax_to_ints(intmax_t arg_val, t_format *conv_params)
{
	t_ints		val;

	val.s_int = 0;
	if (conv_params->len_mod == LEN_MOD_NA)
		val.s_int = (int)arg_val;
	else if (conv_params->len_mod == LEN_MOD_HH)
		val.s_char = (char)arg_val;
	else if (conv_params->len_mod == LEN_MOD_H)
		val.s_short = (short)arg_val;
	else if (conv_params->len_mod == LEN_MOD_L)
		val.s_lint = (long)arg_val;
	else if (conv_params->len_mod == LEN_MOD_LL)
		val.s_llint = (long long)arg_val;
	else if (conv_params->len_mod == LEN_MOD_Z)
		val.s_size_t = (ssize_t)arg_val;
	else if (conv_params->len_mod == LEN_MOD_J)
		val.s_intmax = (intmax_t)arg_val;
	return (val);
}

/*
** Convert the intmax_t `arg_val` to a string based on the base given
** as argument and on the `len_mod` member value in the t_format structure.
*/

static char		*int_arg_val_to_str_conv(intmax_t arg_val, const char *base,
					t_format *conv_params)
{
	t_ints		val;

	val = convert_imax_to_ints(arg_val, conv_params);
	if (conv_params->len_mod == LEN_MOD_HH)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_char, base)
										: ft_uimaxtoa_base(val.u_char, base));
	else if (conv_params->len_mod == LEN_MOD_H)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_short, base)
										: ft_uimaxtoa_base(val.u_short, base));
	else if (conv_params->len_mod == LEN_MOD_L)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_lint, base)
										: ft_uimaxtoa_base(val.u_lint, base));
	else if (conv_params->len_mod == LEN_MOD_LL)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_llint, base)
										: ft_uimaxtoa_base(val.u_llint, base));
	else if (conv_params->len_mod == LEN_MOD_J)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_intmax, base)
										: ft_uimaxtoa_base(val.u_intmax, base));
	else if (conv_params->len_mod == LEN_MOD_Z)
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_size_t, base)
										: ft_uimaxtoa_base(val.u_size_t, base));
	else
		return (conv_params->is_signed ? ft_imaxtoa_base(val.s_int, base)
										: ft_uimaxtoa_base(val.u_int, base));
}

/*
** Convert the intmax_t `arg_value` to a string based on the `type_char` member
** value in the t_format structure.
*/

char			*int_arg_val_to_str(intmax_t arg_val, t_format *conv_params)
{
	char		*str;

	if ((conv_params->flags & FL_NULL) && (conv_params->flags & FL_PREC)
			&& !conv_params->prec)
		str = ft_strnew(0);
	else if (conv_params->type_char == 'o')
		str = int_arg_val_to_str_conv(arg_val, OCT_BASE, conv_params);
	else if (conv_params->type_char == 'x')
		str = int_arg_val_to_str_conv(arg_val, L_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'X')
		str = int_arg_val_to_str_conv(arg_val, U_HEX_BASE, conv_params);
	else if (conv_params->type_char == 'u')
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	else if (conv_params->type_char == 'b')
		str = int_arg_val_to_str_conv(arg_val, BIN_BASE, conv_params);
	else
		str = int_arg_val_to_str_conv(arg_val, DEC_BASE, conv_params);
	return (str);
}
