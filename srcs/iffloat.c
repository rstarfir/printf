/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/17 19:00:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

void			outputthis(t_parser *f, long long int nbr)
{
	char	*nonfr;
	char	*frac;
	char	point[2];
	char	*s;

	nonfr = ft_itoabase_unsigned(f->int_part, 10);
	frac = ft_itoabase_unsigned(nbr, 10);
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

int				acc_round(long double do_n, long long int nbr)
{
	if (nbr % 2 == 1)//check if nbr is odd
	{
		if ((nbr = (do_n * 10)) % 10 >= 5) //checks if 34.5 -> 345 and >= 5
			((nbr = (do_n * 10)) % 10 >= 5) ? (nbr = (nbr / 10) + 1) : (nbr /= 10);
		else if ((nbr = (do_n * 10)) % 10 < 5)//checks if 34.5 -> 345 and < 5
			((nbr = (do_n * 10)) % 10 >= 5) ? (nbr = (nbr / 10) + 1) : (nbr /= 10);
	}
	else
	{
		if ((nbr = (do_n * 10)) % 10 > 5)
			((nbr = (do_n * 10)) % 10 >= 5) ? (nbr = (nbr / 10) + 1) : (nbr /= 10);
		else if ((nbr = (do_n * 10)) % 10 <= 5)
			((nbr = (do_n * 10)) % 10 >= 5) ? (nbr = (nbr / 10) + 1) : (nbr /= 10);
	} 
	return (nbr);
}

long long int		doubleprec(t_parser *f, long long int nbr, long double do_n)
{
	if (f->double_prec < 0)
		f->double_prec = 6;
	if (f->double_prec== 6)
	{
		nbr = (do_n *= 1000000);//6 digits after floating point
		nbr = acc_round(do_n, nbr);//rounding
	}
	else if (f->double_prec > 0)
	{
		nbr = (do_n *= (ft_power(10, f->double_prec)));
		nbr = acc_round(do_n, nbr);
	}
	else if (f->double_prec == 0)
	{
		nbr += f->int_part;
		nbr = acc_round(do_n, nbr);
		f->int_part += nbr;
		nbr = 0;
	}
	return (nbr);
}

void			iffloat(t_parser *f, va_list ap)
{
	long double			do_n;
	long long int		nbr;

	if (f->size == L || f->size == 0)
		do_n = va_arg(ap, double);
	if (f->size == UCL)
		do_n = va_arg(ap, long double);
	if (do_n < 0)
	{
		do_n *= -1;
		f->flags[FSFL] = '-';
	}
	f->int_part = do_n;//put integer part in array
	do_n -= (long double)f->int_part;
	nbr = 0;//0.__ left
	//ft_putnbr((int)f->int_part);
	//write(1, ".", 10);
	nbr = doubleprec(f, nbr, do_n);
	outputthis(f, nbr);
	//printf("\n%lld", nbr);
}