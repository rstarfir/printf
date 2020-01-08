/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:36:10 by rstarfir          #+#    #+#             */
/*   Updated: 2020/01/04 16:54:52 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../includes/printf.h"
#include <stdio.h>
<<<<<<< HEAD
/*
long long int		acc_round(double dou_n, long long int number)
=======

void			outputthis(t_parser *f)
{
	char	point[2];
	char	*s;

	f->nonfr = ft_itoabase_unsigned(f->int_part, 10);
	point[0] = '.';
	point[1] = 0;
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->precision == 0)
		f->nprinted += write(1, f->nonfr, ft_strlen(f->nonfr));
	else
	{
		s = (ft_strjoin(f->nonfr, ft_strjoin(point, f->frac)));
		f->nprinted += write(1, s, ft_strlen(s));
	}
}

int				acc_round(long double do_n, long long int nbr)
>>>>>>> e0892d03f9fa091609c06ab8ee7ca958648cfc79
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

long long int		doubleprec(t_parser *f, long long int nbr, long double do_n)
{
	int		i;
	
	i = 0;
	if (f->double_prec < 0)
		f->double_prec = 6;
	if (f->double_prec > 0)
	{
		while (i < f->double_prec) // i <= 3
		{
			//printf("\nnbr1 %lld\n" , nbr);
			nbr = (do_n *= 10);//0.05 = 0
			f->frac = ft_itoabase(nbr, 10);//005
			//printf("\nf->frac %s\n" , f->frac);
			f->nprinted += write(1, f->frac, ft_strlen(f->frac));
			i++;
		}
		nbr = acc_round(do_n, nbr);
	}
	if (f->double_prec == 0)
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
	f->nonfr = ft_itoabase_unsigned(f->int_part, 10);
	f->nprinted += write(1, f->nonfr, ft_strlen(f->nonfr));
	f->nprinted += write(1, ".", 10);
	nbr = doubleprec(f, nbr, do_n);
	
	//outputthis(f);
	//printf("\n%lld", nbr);
}
*/
#include "../includes/printf.h"
#include <stdio.h>

void				left_alligned(t_parser *f, int len, char *s)
{
	
}

long long int		acc_round(long double do_n, long long int nbr)
{
	int j;

	j = 0;
	if (nbr % 2 == 1)
	{
		if ((nbr = (long long int)(do_n * 10)) % 10 >= 5)
		{
			nbr = (nbr / 10) + 1;
		}
		else if ((nbr = (do_n * 10)) % 10 < 5)
		{
			nbr = (nbr / 10);
		}
	}
	else
	{
		if ((nbr = (do_n * 10)) % 10 > 5)
			nbr = (nbr / 10) + 1;
		else if ((nbr = (do_n * 10)) % 10 <= 5)
		{
			nbr /= 10;
		while (++j < 2)
			{
				if ((nbr = (do_n *= 10)) % 10 > 0)
					nbr = (nbr / (10 * j) + 1);
				else
					nbr /= (10 * j);
			}
			
		}
	}
	return (nbr);
}

long long int		doubleprec(t_parser *f, long long int nbr, long double do_n)
{
	int		i;
	
	i = 0;
	if (f->double_prec < 0)
		f->double_prec = 6;
	if (f->double_prec > 0)
	{
		nbr = do_n -= f->int_part;
		while (++i <= f->double_prec)
		{
			do_n -= nbr;
			nbr = (do_n *= 10);
			if (i == f->double_prec)
				nbr = acc_round(do_n, nbr);;
			f->frac = ft_itoabase(nbr, 10);
			f->nprinted += write(1, f->frac, ft_strlen(f->frac));
		}
	}
	if (f->double_prec == 0)
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
	char				*s;

	if (f->size == L || f->size == 0)
		do_n = va_arg(ap, double);
	if (f->size == UCL)
		do_n = va_arg(ap, long double);
	if (do_n < 0)
	{
		do_n *= -1;
		f->flags[FSFL] = '-';
	}
<<<<<<< HEAD
	s = ft_itoabase(number, 10);
}
 */
=======
	s = ft_itoabase_unsigned((long long)do_n * ft_power(10, f->double_prec + 1), 10);
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned(f, ft_strlen(s), s);
	f->int_part = do_n;
	f->nonfr = ft_itoabase_unsigned(f->int_part, 10);
	f->nprinted += write(1, f->nonfr, ft_strlen(f->nonfr));
	if (f->double_prec != 0)
		f->nprinted += write(1, ".", 1);
	doubleprec(f, nbr, do_n);
}
>>>>>>> e0892d03f9fa091609c06ab8ee7ca958648cfc79
