/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/06 19:21:54 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>
/*
long long int		acc_round(double dou_n, long long int number)
{
	printf("number0--%lld\n", number);
	if (number % 2 == 1)
	{
		printf("Qenumber--%lld\n", number);
		if ((number = (int)(dou_n * 10)) % 10 >= 5)
		{
			printf("numberm--%lld\n", number);
			number = (number / 10) + 1;
			printf("enumber--%lld\n", number);
		}
		else if ((number = (int)(dou_n * 10)) % 10 < 5)
			number = (number / 10);
	}
	else
	{
		printf("Qwnumber--%lld\n", number);
		if ((number = (int)(dou_n * 10)) % 10 > 5)
		{
			printf("Qenumber--%lld\n", number);
			number = (number / 10) + 1;
		}
		else if ((number = (int)(dou_n * 10)) % 10 <= 5)
		{
			number = (number / 10);
			printf("Qgnumber--%lld\n", number);
		}
	}
	return (number);
}

void	iffloat(t_parser *f, va_list ap)
{
	double dou_n;
	long long int number;
	char *s;
	
	dou_n = va_arg(ap, double);
	f->int_part = (int)dou_n;//put integer part in array
	number = dou_n -= f->int_part;//0.__ left


	printf("Qinteger--%d\n", f->int_part);
	if (f->precision == -1)
	{
		number = (int)(dou_n * 1000000);//6 digits after floating point
		number = acc_round(dou_n, number);//rounding
		
	}
	else if (f->precision == 0)
	{
		number += f->int_part;
		printf("Qe2number--%lld\n", number);
		number = acc_round(dou_n, number);
		f->int_part += number;
		number = 0;
		printf("int--%d\n", f->int_part);
	}
	else if (f->precision > 0)
	{
		number = (int)(dou_n * (ft_power(10, f->precision)));
		number += acc_round(dou_n, number);
		printf("Qnumber--%lld\n", number);
	}
	s = ft_itoabase(number, 10);
}
 */