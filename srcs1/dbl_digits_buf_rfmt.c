/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_digits_buf_rfmt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:19:31 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 13:37:45 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Check that from index `begin' to then end of `digits', there are only zeros.
*/

static int		check_end_digits(char *digits, size_t begin)
{
	size_t		i;

	i = begin;
	while (digits[i])
	{
		if (digits[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static char		*handle_conv_switch(char **digits, int exponent,
												t_format *conv_params)
{
	handle_g_conv_spec(exponent, conv_params);
	if (!ft_strpad_left(digits, '0', -exponent))
		return (NULL);
	return (*digits);
}

static char		*round_nb(char *digits, int *exponent, t_format *conv_params)
{
	size_t		i;
	t_uint		carry;

	i = ft_max(ft_tolower(conv_params->type_char) == 'e' ? 0 : *exponent, 0)
			+ conv_params->prec;
	if (!digits[i + 1] || digits[i + 1] < '5' || ((digits[i + 1] == '5')
			&& !((digits[i] - '0') & 1U) && check_end_digits(digits, i + 2)))
		return (digits);
	carry = 1U;
	while (i && carry)
	{
		if ((digits[i] = (digits[i] == '9') ? '0' : digits[i] + 1) != '0')
			carry = 0U;
		--i;
	}
	if (i || !carry)
		return (digits);
	if (digits[i] == '9')
	{
		digits[i] = '1';
		digits[ft_max((*exponent)++, 0) + conv_params->prec + 1] = '0';
	}
	else
		digits[i]++;
	return (digits);
}

static char		*add_zeros_right(char **digits, int exponent,
									t_format *conv_params)
{
	if (exponent <= 0)
		ft_strpad_right(digits, '0',
				ft_max(conv_params->prec - (ft_strlen(*digits) - 1), 0));
	else
		ft_strpad_right(digits, '0',
			ft_max(exponent - (ft_strlen(*digits) - 1), 0)
			+ conv_params->prec - ((exponent > (int)ft_strlen(*digits) - 1) ?
			0 : ft_strlen(*digits + exponent + 1)));
	return (*digits);
}

char			*reformat_digits_buf(char **digits, int *exponent,
											t_format *conv_params)
{
	if (*exponent < 0 && ft_tolower(conv_params->type_char) == 'f')
		if (!ft_strpad_left(digits, '0', -*exponent))
			return (NULL);
	if (!add_zeros_right(digits, *exponent, conv_params))
		return (NULL);
	round_nb(*digits, exponent, conv_params);
	if ((conv_params->flags & FL_TRIM) && *exponent == -4
			&& ft_tolower(conv_params->type_char) == 'e')
		if (!handle_conv_switch(digits, *exponent, conv_params))
			return (NULL);
	return (*digits);
}
