/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:40:24 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:58:50 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				is_max_exp(t_dbls *arg_val, t_parser *conv_params)
{
	if ((conv_params->size == UCL
	&& arg_val->ldbl_parts.exp == 0x7FFF)
		|| (conv_params->size != UCL
			&& arg_val->dbl_parts.exp == 0x7FF))
		return (1);
	else
		return (0);
}

char			*handle_zero(char *dff, t_parser *format)
{
	int		preccopy;
	char	*temp;

	preccopy = format->flprecision;
	while (preccopy-- > 0)
		dff = ft_strjoinf(dff, "0", dff, 0);
	if (format->flprecision > 0)
	{
		temp = ft_strndup(dff, format->flprecision);
		free(dff);
		temp = ft_strjoinf("0.", temp, 0, temp);
		return (temp);
	}
	else
	{
		free(dff);
		return (ft_strdup("0"));
	}
}

static	char	*handle_inf_nan(t_dbls *arg_val, t_parser *conv_params)
{
	if (conv_params->size == UCL)
	{
		if (!arg_val->ldbl_parts.mant)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
	else
	{
		if (!arg_val->dbl_parts.mant)
			return (ft_strdup("inf"));
		else
			return (ft_strdup("nan"));
	}
}

static	char	*update_flags_limit_values(char *val_str, t_parser *conv_params)
{
	if (conv_params->flags & ZFL)
		conv_params->flags ^= ZFL;
	if (!ft_strcmp(val_str, "nan"))
	{
		conv_params->flags |= (PFL | SFL);
		conv_params->flags ^= (PFL | SFL);
		conv_params->before_num = 0;
	}
	if (conv_params->format[conv_params->i] == 'F')
		val_str = ft_toupperstring(val_str);
	return (val_str);
}

char			*format_inf_nan(t_dbls *arg_val, t_parser *conv_params)
{
	char	*digits;

	if (!(digits = handle_inf_nan(arg_val, conv_params)))
		return (NULL);
	digits = (update_flags_limit_values(digits, conv_params));
	if ((conv_params->flags & SFL) && !conv_params->before_num
		&& (ft_strequ(digits, "inf") || ft_strequ(digits, "INF")))
		conv_params->before_num = ' ';
	if (conv_params->flags & MFL)
	{
		conv_params->flags &= 0xFFFFFFFF - ZFL;
		digits = left_width_format_double(digits, conv_params);
	}
	else
		digits = right_width_format_double(digits, conv_params);
	return (digits);
}
