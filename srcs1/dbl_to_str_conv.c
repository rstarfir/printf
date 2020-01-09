/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_to_str_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:17:58 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 15:23:24 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Calculate the value of val_exponent and val_mantissa for each representation
** based on the following formulae:
**  - normalized number:
** ( 1 + mantissa / 2^(nb mantissa bits) ) * 2 ^ (exp + 1 - 2^(nb exp bits - 1))
**  - denormalized number:
** ( mantissa / 2^(nb of mantissa bits) ) * 2 ^ ( 1 + 1 - 2^(nb exp bits - 1) )
**
**  Representations:
**  - 64-bit denormalized:
**          value = ( mantissa / 2^52 ) * 2 ^ (1 - 1023)
**                = mantissa * 2 ^ ( 1 - 1023 - 52 )
**  - 64-bit normalized:
**			value = ( 1 + mantissa / 2^52 ) * 2 ^ ( exponent - 1023 )
**                = ( 2^52 + mantissa ) * 2 ^ ( exponent - 1023 - 52 )
**  - 80-bit denormalized:
**          value = ( mantissa / 2^63 ) * 2 ^ (1 - 16383)
**                - mantissa * 2 ^ ( 1 - 16383 - 63 )
**  - 80-bit normalized:
**          value = ( 1 + mantissa / 2^63 ) * 2 ^ ( exponent - 16383 )
**                = ( 2^63 + mantissa ) * 2 ^ ( exponent - 16383 - 63 )
*/

static void			init_mantissa_exponent(t_dbls *arg_val,
						t_ullint *val_mantissa, int *val_exponent,
							t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
	{
		*val_mantissa = (t_ullint)arg_val->ldbl_parts.mantissa
					+ ((arg_val->ldbl_parts.exponent) ? (1ULL << 63) : 0ULL);
		*val_exponent = (int)arg_val->ldbl_parts.exponent - 16446
					+ ((arg_val->ldbl_parts.exponent) ? 0 : 1);
	}
	else
	{
		*val_mantissa = (t_ullint)arg_val->dbl_parts.mantissa
						+ ((arg_val->dbl_parts.exponent) ? (1ULL << 52) : 0ULL);
		*val_exponent = (int)arg_val->dbl_parts.exponent - 1075
						+ ((arg_val->dbl_parts.exponent) ? 0 : 1); // в каком случае прибавляем единицу.
	}
}

/*
** First, represent the floating-point number as a pair of integers in the
** equation:
**                 val_mantissa * 2 ^ (val_exponent)
** Then, represent it as a fraction of two big int depending on the value of
** val_exponent:
**   - val_exponent >= 0:          val_mantissa * 2 ^ (val_exponent)
**                                ---------------------------------
**                                               1
**   - val_exponent < 0:                    val_mantissa
**                                ---------------------------------
**                                       2 ^ (-val_exponent)
*/

static void			initialize_fraction(t_dbls *arg_val, t_bigint *val_num,
									t_bigint *val_den, t_format *conv_params)
{
	t_ullint		val_mantissa;
	int				val_exponent;

	val_mantissa = 0ULL;
	val_exponent = 0;
	init_mantissa_exponent(arg_val, &val_mantissa, &val_exponent, conv_params);
	ft_uimax_to_bigint(val_mantissa, val_num);
	if (val_exponent >= 0)
		ft_bigint_shiftleft(val_num, val_exponent);
	else
		ft_bigint_shiftleft(val_den, -val_exponent);
}

/*
** Scale the fraction so that 0 <= val_num / val_den < 10, ie. first digit is in
** the ones place.
** Example:
**   - 142.5 would become 1.425 --> val_num / (val_den * 10^2)
**   - 0.01425 would become 1.425 --> val_num / (val_den * 10^-2)
**                                --> (val_num * 10^2) / val_den
*/

static void			scale_fraction(t_bigint *val_num, t_bigint *val_den,
									int exponent)
{
	t_bigint		pow10;

	pow10 = exponent > 0 ? ft_bigint_pow10(exponent) : ft_bigint_pow10(-exponent);
	if (exponent > 0)
		*val_den = ft_bigint_multiply(val_den, &pow10);
	else if (exponent < 0)
		*val_num = ft_bigint_multiply(val_num, &pow10);
}

/*
** Get the power of ten of the floating-point number written in scientific
** notation.
** Example: 142.5 = 1.425 * 10 ^ 2 --> exponent = 2
*/

void				get_first_digit_exponent(t_dbls *arg_val, int *exponent,
												t_format *conv_params)
{
	if (conv_params->len_mod == LEN_MOD_CAP_L)
		*exponent = ft_exponent(arg_val->ldbl);
	else
		*exponent = ft_exponent(arg_val->dbl);
}

/*
** Get the representation of the floating-point number as a fraction of 2 big
** ints which is superior to 0 and strictly inferior to 10.
** Extract the digits as the integer division of the numerator by the
** denominator.
** Compute the remainder by substracting the digit extracted
** (ex: 1.425 - 1 --> 0.425).
** Scale the next digit in the first place (ex: 0.425 * 10 --> 4.25).
** Repeat until numerator equals 0.
*/

void				dragon4(t_dbls *arg_val, char *digits, int *exponent,
							t_format *conv_params)
{
	t_bigint		val_num;
	t_bigint		val_den;
	t_bigint		bigint_tmp;
	int				i;
	int				digit;

	val_num = (t_bigint){0, {0}};
	val_den = (t_bigint){1, {0}};
	val_den.blocks[0] = 1;
	initialize_fraction(arg_val, &val_num, &val_den, conv_params);
	get_first_digit_exponent(arg_val, exponent, conv_params);
	scale_fraction(&val_num, &val_den, *exponent);
	i = 0;
	while (val_num.length > 0 && i < BUF_DIGITS_SIZE)
	{
		digit = ft_bigint_divide(&val_num, &val_den);
		digits[i++] = '0' + digit;
		bigint_tmp = val_den;
		ft_bigint_multiply_uint(&bigint_tmp, digit);
		ft_bigint_subst(&val_num, &bigint_tmp, &val_num);
		ft_bigint_multiply_uint(&val_num, 10);
	}
}
