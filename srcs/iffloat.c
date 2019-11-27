/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/27 23:36:46 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
void left_aligned_float(t_parser *f, int length, char *s)
{
	int i;
	char k;

	k = ' ';
	i = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1); 
		if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == -1)) && (k = '0'))
	if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	f->nprinted += write(1, s, length);
}
void	iffloat(t_parser *f, va_list ap)
{
	long long number;
	char *s;
	number = (long long int)va_arg(ap, long long int);
	
	if (f->precision == -1)
	{
		number *= 10 ^ 6;
		if (number  >= 5)
			number += 1;
	}
	if (f->precision == 0)
	{
		if (number % 2 == 1)
		{
			if ((number * 10) % 10 >= 5)
				number += 1;
		}
		else
			if (number % 10 > 5)
				number += 1;
	}
	if (f->precision < 0)
	{
		number *= 10 ^ f->precision;
		if ((number * 10) % 10 >= 5)
			number += 1;
	}
	if (number < 0)
	{
		number *= -1;
		f->flags[FSFL] = '-';
	}
	s = ft_itoabase(number, 10);
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned_float(f, ft_strlen(s), s);
	}
	f->nprinted += write(1, s, ft_strlen(s));
	free(s);
}
