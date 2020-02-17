/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_alignment_put_extra_symbs.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:36:36 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:58:31 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			put_before_num_symb(char **digits, t_parser conv_params)
{
	if (conv_params.before_num == '-')
		*digits = ft_strjoinf("-", *digits, 0, *digits);
	if (conv_params.before_num == ' ')
		*digits = ft_strjoinf(" ", *digits, 0, *digits);
	if (conv_params.before_num == '+')
		*digits = ft_strjoinf("+", *digits, 0, *digits);
}

char			*right_width_format_double(char *digits, t_parser *conv_params)
{
	int k;

	k = ft_strlen(digits);
	if (!(conv_params->flags & ZFL))
		put_before_num_symb(&digits, *conv_params);
	if (conv_params->flags & ZFL)
		while (conv_params->width > k + (conv_params->before_num != 0))
		{
			digits = ft_strjoinf("0", digits, 0, digits);
			conv_params->width--;
		}
	else
		while (conv_params->width > k + (conv_params->before_num != 0))
		{
			digits = ft_strjoinf(" ", digits, 0, digits);
			conv_params->width--;
		}
	if (conv_params->flags & ZFL)
		put_before_num_symb(&digits, *conv_params);
	return (digits);
}

char			*left_width_format_double(char *digits, t_parser *conv_params)
{
	int k;

	k = ft_strlen(digits);
	if (!(conv_params->flags & ZFL))
		put_before_num_symb(&digits, *conv_params);
	if (conv_params->flags & ZFL)
		while (conv_params->width > k + (conv_params->before_num != 0))
		{
			digits = ft_strjoinf("0", digits, 0, digits);
			conv_params->width--;
		}
	else
		while (conv_params->width > k + (conv_params->before_num != 0))
		{
			digits = ft_strjoinf(digits, " ", digits, 0);
			conv_params->width--;
		}
	if (conv_params->flags & ZFL)
		put_before_num_symb(&digits, *conv_params);
	return (digits);
}

char			*add_point(char *digits, t_parser *conv_params)
{
	if (conv_params->flags & OFL)
		if (!ft_strchr(digits, '.'))
			digits = ft_strjoinf(digits, ".", digits, 0);
	return (digits);
}
