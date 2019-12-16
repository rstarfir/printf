/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/16 21:24:01 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

void			outputthis(t_parser *f, long long int number)
{
	char	*nonfr;
	char	*frac;
	char	point[2];
	char	*s;

	//printf("\n%lld", number);
	nonfr = ft_itoabase_unsigned(f->int_part, 10);
	//printf("%lld\n", f->int_part);
	frac = ft_itoabase_unsigned(number, 10);
	point[0] = '.';
	point[1] = 0;
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->precision == 0)
		f->nprinted += write(1, nonfr, ft_strlen(nonfr));
	else
	{
		s = (ft_strjoin(nonfr, ft_strjoin(point, frac)));
		f->nprinted += write(1, s, ft_strlen(s));
	}
}

int				acc_round(long double dou_n, long long int number)
{
	if (number % 2 == 1)//check if number is odd
	{
		if ((number = (dou_n * 10)) % 10 >= 5) //checks if 34.5 -> 345 and >= 5
		{
			if ((number = (dou_n * 10)) % 10 >= 5)
				number = (number / 10) + 1;// returns to prev value 34 and adds 1 -> 35
			else 
				number = number / 10;
		}
		else if ((number = (dou_n * 10)) % 10 < 5)//checks if 34.5 -> 345 and < 5
		{
			if ((number = (dou_n * 10)) % 10 >= 5)
				number = (number / 10) + 1;
			else
				number = (number / 10);
		}
	}
	else
	{
		if ((number = (dou_n * 10)) % 10 > 5)
		{
			if ((number = (dou_n * 10)) % 10 >= 5)
				number = (number / 10) + 1;
			else
				number /= 10;
		}
		else if ((number = (dou_n * 10)) % 10 <= 5)
		{
			if ((number = (dou_n * 10)) % 10 >= 5)
				number = (number / 10) + 1;
			else
				number /= 10;
		}	
	} 
	return (number);
}

long long int		doubleprec(t_parser *f, long long int number, long double dou_n)
{
	if (f->double_prec < 0)
		f->double_prec = 6;
	if (f->double_prec== 6)
	{
		number = (dou_n *= 1000000);//6 digits after floating point
		number = acc_round(dou_n, number);//rounding
	}
	else if (f->double_prec > 0)
	{
		number = (dou_n *= (ft_power(10, f->double_prec)));
		number = acc_round(dou_n, number);
	}
	else if (f->double_prec == 0)
	{
		number += f->int_part;
		number = acc_round(dou_n, number);
		f->int_part += number;
		number = 0;
	}
	return (number);
}

void			iffloat(t_parser *f, va_list ap)
{
	long double			dou_n;
	long long int	number;
		
	if (f->size == L || f->size == 0)
		dou_n = va_arg(ap, double);
	if (f->size == UCL)
		dou_n = va_arg(ap,long double);
	if (dou_n < 0)
	{
		dou_n *= -1;
		f->flags[FSFL] = '-';
	}
	f->int_part = dou_n;//put integer part in array
	dou_n -= (long double)f->int_part;
	number = 0;//0.__ left
	//ft_putnbr((int)f->int_part);
	//write(1, ".", 10);
	number = doubleprec(f, number, dou_n);
	outputthis(f, number);
	//printf("\n%lld", number);
}