/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:37:56 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 11:51:05 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Extract the next value in the va_list as an intmax_t based on the
** parameters in the `t_format' structure.
*/

static intmax_t	get_int_arg_val(t_format *conv_params, va_list args)
{
	intmax_t	arg_val;

	arg_val = 0;
	if (conv_params->len_mod == LEN_MOD_HH)
		arg_val = (char)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_H)
		arg_val = (short)va_arg(args, int);
	else if (conv_params->len_mod == LEN_MOD_L)
		arg_val = (long)va_arg(args, long);
	else if (conv_params->len_mod == LEN_MOD_LL)
		arg_val = (long long)va_arg(args, long long);
	else if (conv_params->len_mod == LEN_MOD_J)
		arg_val = (intmax_t)va_arg(args, intmax_t);
	else if (conv_params->len_mod == LEN_MOD_Z)
		arg_val = (ssize_t)va_arg(args, ssize_t);
	else
		arg_val = (int)va_arg(args, int);
	return (arg_val);
}

/*
** Format the `val_str` string depending on the conversion specification.
*/

static char		*format_int_str(char *val_str, t_format *conv_params)
{
	int			nb_zeros_prec;
	int			nb_digits;
	int			padding;

	conv_params->is_neg = (val_str[0] == '-') ? 1 : 0;
	nb_digits = ft_strlen(val_str) - conv_params->is_neg;
	nb_zeros_prec = get_nb_zeros_prec(nb_digits, conv_params);
	if (nb_zeros_prec)
		if (!prepend_prec(&val_str, nb_zeros_prec))
			return (NULL);
	if (has_sign(nb_zeros_prec, conv_params))
		if (!prepend_sign(&val_str, conv_params))
			return (NULL);
	if (has_prefix(conv_params))
		if (!prepend_prefix(&val_str, conv_params))
			return (NULL);
	if ((padding = conv_params->width - ft_strlen(val_str)) > 0)
		if (!add_padding(&val_str, padding, conv_params))
			return (NULL);
	return (val_str);
}

char			*get_formatted_str_from_int(t_format *conv_params, va_list args)
{
	intmax_t	arg_val;
	char		*val_str;

	if (!(arg_val = get_int_arg_val(conv_params, args)))
		conv_params->flags |= FL_NULL;
	if (!(val_str = int_arg_val_to_str(arg_val, conv_params)))
		return (NULL);
	if (!(val_str = format_int_str(val_str, conv_params)))
		return (NULL);
	return (val_str);
}
