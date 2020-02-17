/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:09:04 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 19:24:08 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		set_values(t_dbls *arg_val, t_ullint *val_mant,
							int *val_exp, t_parser *conv_params)
{
	if (conv_params->size == UCL)
	{
		*val_mant = arg_val->ldbl_parts.mant +
				((arg_val->ldbl_parts.exp) ? (1ULL << 63) : 0ULL);
		*val_exp = (int)arg_val->ldbl_parts.exp - 16446 +
				((arg_val->ldbl_parts.exp) ? 0 : 1);
	}
	else
	{
		*val_mant = arg_val->dbl_parts.mant +
				((arg_val->dbl_parts.exp) ? (1ULL << 52) : 0ULL);
		*val_exp = (int)arg_val->dbl_parts.exp - 1075 +
				((arg_val->dbl_parts.exp) ? 0 : 1);
	}
}

static void		set_fraction(t_dbls *arg_val, t_bigint *val_num,
								t_bigint *val_den, t_parser *conv_params)
{
	t_ullint		val_mant;
	int				val_exp;

	val_mant = 0ULL;
	val_exp = 0;
	set_values(arg_val, &val_mant, &val_exp, conv_params);
	ft_ullint_to_bigint(val_mant, val_num);
	if (val_exp >= 0)
		ft_bigint_shiftleft(val_num, val_exp);
	else
		ft_bigint_shiftleft(val_den, -val_exp);
}

static void		scale_fraction(t_bigint *val_num, t_bigint *val_den,
								int exponent)
{
	t_bigint		pow10;

	pow10 = exponent > 0 ? ft_bigint_x10(exponent) : ft_bigint_x10(-exponent);
	if (exponent > 0)
		*val_den = ft_bigint_multiply(val_den, &pow10, 0);
	else if (exponent < 0)
		*val_num = ft_bigint_multiply(val_num, &pow10, 0);
}

void			get_first_digit_exponent(t_dbls *arg_val, int *exponent,
										t_parser *conv_params)
{
	if (conv_params->size == UCL)
		*exponent = ft_exponent(arg_val->ldbl);
	else
		*exponent = ft_exponent(arg_val->dbl);
}

void			dragon4(t_dbls *arg_val, char *digits,
						int *exponent, t_parser *conv_params)
{
	t_bigint		val_num;
	t_bigint		val_den;
	t_bigint		bigint_tmp;
	int				i;
	int				digit;

	val_num = (t_bigint){0, {0}};
	val_den = (t_bigint){1, {0}};
	val_den.blocks[0] = 1;
	set_fraction(arg_val, &val_num, &val_den, conv_params);
	get_first_digit_exponent(arg_val, exponent, conv_params);
	scale_fraction(&val_num, &val_den, *exponent);
	i = 0;
	while (val_num.length > 0 && i < BUF_DIGITS_SIZE)
	{
		digit = ft_bigint_divide(&val_num, &val_den);
		digits[i++] = '0' + digit;
		bigint_tmp = val_den;
		ft_bi_uint_mult(&bigint_tmp, digit);
		ft_bigint_subt(&val_num, &bigint_tmp, &val_num);
		ft_bi_uint_mult(&val_num, 10);
	}
}
