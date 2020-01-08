/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:14:27 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 16:14:45 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				get_nb_zeros_prec_dbl(int nb_digits, t_format *conv_params)
{
	int			nb;

	nb = 0;
	if ((conv_params->flags & FL_ZERO) && !(conv_params->flags & FL_MINUS))
		nb = (int)ft_max(conv_params->width
				- (nb_digits + ((conv_params->is_neg)
						|| (conv_params->flags & FL_PLUS)
						|| (conv_params->flags & FL_SPACE))), 0);
	return (nb);
}

/*
** Prepend zeros for the precision to `val_str`. If `val_str` corresponds to a
** negative number, replace the `-` sign by a zero and pad with
** `nb_zeros_prec` - 1.
*/

char			*prepend_prec(char **val_str, int nb_zeros_prec)
{
	if ((*val_str)[0] == '-')
	{
		(*val_str)[0] = '0';
		ft_strpad_left(val_str, '0', nb_zeros_prec - 1);
	}
	else
		ft_strpad_left(val_str, '0', nb_zeros_prec);
	return (*val_str);
}

/*
** Check if `val_str` should be prefixed with a sign symbol ('-', '+' or ' '):
**  - type is 'd' or 'i',
**		1) - the value is a negative number,
**		   - at least one zero has been added for the precision/padding;
**	or  2) - the value is a positive number,
**         - either flag FL_PLUS ('+') or FL_SPACE (' ') is set.
*/

int				has_sign(int nb_zeros_prec, t_format *conv_params)
{
	return (ft_instr(conv_params->type_char, SIGNED_TYPES)
				&& ((conv_params->is_neg && nb_zeros_prec)
					|| (!conv_params->is_neg && ((conv_params->flags & FL_PLUS)
						|| (conv_params->flags & FL_SPACE)))));
}

/*
** Prepend sign after the precision has been set.
*/

char			*prepend_sign(char **val_str, t_format *conv_params)
{
	if (conv_params->is_neg)
		ft_strprepend("-", val_str);
	else if (conv_params->flags & FL_PLUS)
		ft_strprepend("+", val_str);
	else if (conv_params->flags & FL_SPACE)
		ft_strprepend(" ", val_str);
	return (*val_str);
}

/*
** Add padding after or before the formated value depending on the flag
** `FL_MINUS` value. Pads with zeros if `FL_MINUS` flag not set and no precision
** is given.
*/

char			*add_padding(char **val_str, int padding, t_format *conv_params)
{
	if (conv_params->flags & FL_MINUS)
		ft_strpad_right(val_str, ' ', padding);
	else if (!ft_instr(conv_params->type_char, INT_TYPES)
			&& (conv_params->flags & FL_ZERO))
		ft_strpad_left(val_str, '0', padding);
	else
		ft_strpad_left(val_str, ' ', padding);
	return (*val_str);
}
