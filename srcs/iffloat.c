/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/28 23:26:51 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

void	iffloat(t_parser *f, va_list ap)
{
	double dou_n;
	long long int number;
	char *s;
	
	dou_n = va_arg(ap, double);
	number = (int)dou_n;

	printf("dou_n %f \n", dou_n);
	printf("number %lld \n", number);
	if (f->precision == 0)
	{
		if (number % 2 == 1)
		{
			printf("number %lld \n", number);
			if ((number = (int)(dou_n * 10) % 10) >= 5)
				number += 1;
			else if ((number = (int)(dou_n * 10) % 10) < 5)
				number += 1;
		}
		else
		{
			if ((number = (int)(dou_n * 10)) % 10 > 5)
				number = (number / 10) + 1;
			else if ((number = (int)(dou_n * 10)) % 10 < 5)
				number = (number / 10);
		}
	}
	s = ft_itoabase(number, 10);
	f->nprinted += write(1, s, ft_strlen(s));
	f->nprinted += write(1, ".", 1);
	number = (dou_n -= number);
	if (f->precision == -1)
	{
		number = (dou_n *= ft_power(10, 6));
		if (number % 10 >= 5)
			number += 1;
	}
	else if (f->precision > 0)
	{
		number = (int)(dou_n *= ft_power(10, f->precision));
		if ((number = (int)(dou_n * 10)) % 10 >= 5)
		{
			//printf("number %lld \n", number);
			number = (number / 10) + 1;
		}
		else 
			number = (number / 10);

	}
	else if (number < 0)
	{
		number *= -1;
		f->flags[FSFL] = '-';
	}
	//printf("%lld \n", number);
	s = ft_itoabase(number, 10);
	f->nprinted += write(1, s, ft_strlen(s));
	free(s);
}