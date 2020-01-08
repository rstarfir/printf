/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_formatting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:16:26 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 16:16:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Calculate the number of zeros for the precision:
**     1) FL_PREC flag is set (if precision is given, '0' flag is ignored):
**            nb = MAX(nb of digits, precision) - nb of digits;
**  or
**     2) FL_ZERO flag is set but not FL_MINUS ('-' flag overides '0' flag):
**         a) type is signed ('d' or 'i'):
**            nb = MAX(width - (nb of digits [+ 1 for sign symbol]), 0);
**         b) type is prefixed ('x' or 'X'):
**            nb = MAX(width - (nb of digits + 2), 0);
**         c) type is 'o' or 'u':
**            nb = MAX(width - nb_digits, 0);
**     if:
**         - type is 'o'
**         - FL_HASH flag is set
**         - nb of zeros to add equals to zero
**         and
**                - value is not equal to zero
**            or  - value is zero
**                - FL_PREC flag is set
**                - precision equals zero
**     then, +1 is added to force the increase of the precision.
*/

int				get_nb_zeros_prec(int nb_digits, t_format *conv_params)
{
	int			nb;

	nb = 0;
	if (conv_params->flags & FL_PREC)
		nb = (int)ft_max(nb_digits, conv_params->prec) - nb_digits;
	else if ((conv_params->flags & FL_ZERO) && !(conv_params->flags & FL_MINUS))
	{
		if (ft_instr(conv_params->type_char, SIGNED_TYPES))
			nb = (int)ft_max(conv_params->width
					- (nb_digits + ((conv_params->is_neg)
							|| (conv_params->flags & FL_PLUS)
							|| (conv_params->flags & FL_SPACE))), 0);
		else if (has_prefix(conv_params))
			nb = (int)ft_max(conv_params->width - (nb_digits + 2), 0);
		else
			nb = (int)ft_max(conv_params->width - nb_digits, 0);
	}
	if ((conv_params->type_char == 'o') && (conv_params->flags & FL_HASH)
			&& !nb && (!(conv_params->flags & FL_NULL)
				|| ((conv_params->flags & FL_NULL)
					&& (conv_params->flags & FL_PREC) && !conv_params->prec)))
		nb++;
	return (nb);
}

/*
** Check if `val_str` should have a prefix ('0x' or '0X'):
**  - type has to be either ('x' or 'X'),
**  - FL_HASH flag is set,
**  - value is not zero.
*/

int				has_prefix(t_format *conv_params)
{
	return ((conv_params->flags & FL_POINT)
			|| (ft_instr(conv_params->type_char, TYPE_PREFIX)
				&& conv_params->flags & FL_HASH
				&& !(conv_params->flags & FL_NULL)));
}

/*
** Add the right prefix depending on the type if the flag `FL_HASH` is set.
*/

char			*prepend_prefix(char **val_str, t_format *conv_params)
{
	if (conv_params->type_char == 'o')
		ft_strprepend(PREF_OCT, val_str);
	else if (conv_params->type_char == 'x')
		ft_strprepend(PREF_L_HEX, val_str);
	else if (conv_params->type_char == 'X')
		ft_strprepend(PREF_U_HEX, val_str);
	else if (conv_params->type_char == 'b')
		ft_strprepend(PREF_BIN, val_str);
	return (*val_str);
}
