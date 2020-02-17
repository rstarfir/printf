/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:10:11 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:59:10 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		get_dbl_arg_val(t_dbls *arg_val, t_parser *format,
								va_list args)
{
	if (format->size == UCL)
	{
		if (!(arg_val->ldbl = (t_ldbl)va_arg(args, t_ldbl)))
			format->flags |= NFL;
		if (arg_val->ldbl_parts.sign
			&& !(arg_val->ldbl_parts.exp == 0x7FFF
			&& arg_val->ldbl_parts.mant))
			format->before_num = '-';
	}
	else
	{
		if (!(arg_val->dbl = (double)va_arg(args, double)))
			format->flags |= NFL;
		if (arg_val->dbl_parts.sign
			&& !(arg_val->dbl_parts.exp == 0x7FF
			&& arg_val->dbl_parts.mant))
			format->before_num = '-';
	}
}

static	char	*format_double(char *dff, t_parser *format, int exp)
{
	char	*copy;
	int		carry;

	carry = 0;
	if (ft_strequ(dff, "0"))
		return (handle_zero(dff, format));
	copy = round_first_symbol(&carry, dff, exp, *format);
	round_other_symbols(&carry, exp + format->flprecision, &copy, &dff);
	if (format->flprecision == 0)
		return (return_zero_prec_values(exp, dff, carry));
	else
		return (return_not_zero_prec_values(dff, exp, carry, format));
}

static char		*dbl_arg_val_to_str(t_dbls *arg_val, t_parser *conv_params)
{
	char		*digits;
	int			exponent;

	if (is_max_exp(arg_val, conv_params))
		return (format_inf_nan(arg_val, conv_params));
	if (!(digits = ft_strnew(BUF_DIGITS_SIZE)))
		return (NULL);
	if (!(conv_params->flags & NFL))
		dragon4(arg_val, digits, &exponent, conv_params);
	else
		digits[0] = '0';
	if ((conv_params->flags & SFL) && !conv_params->before_num)
		conv_params->before_num = ' ';
	digits = format_double(digits, conv_params, exponent);
	digits = add_point(digits, conv_params);
	if (conv_params->flags & MFL)
	{
		conv_params->flags &= 0xFFFFFFFF - ZFL;
		digits = left_width_format_double(digits, conv_params);
	}
	else
		digits = right_width_format_double(digits, conv_params);
	return (digits);
}

void			iffloat(t_parser *format, va_list args)
{
	t_dbls		arg_val;
	char		*val_str;

	get_dbl_arg_val(&arg_val, format, args);
	val_str = dbl_arg_val_to_str(&arg_val, format);
	format->nprinted += ft_strlen(val_str);
	ft_putstr(val_str);
	if (val_str)
		free(val_str);
}
