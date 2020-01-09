/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:39:57 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:39:59 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int						ft_max(int one, int two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}

static	void			left_aligned_int(t_parser *f, int length, char *s)
{
	int		i;
	char	k;
	int		copy;

	k = ' ';
	copy = f->precision;
	i = 0;
	if (f->beforeNum && ++i)
	    f->nprinted += write(1, &f->beforeNum, 1);
	while (f->precision > length && f->precision--)
		f->nprinted += write(1, "0", 1);
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
	if (f->flags & ZFL)
	{
		k = '0';
		if (f->beforeNum == '-')
			f->nprinted += write(1, &f->beforeNum, 1);
	}
	if (length == 1 && *s == '0' && f->precision == 0)
		length--;
	while (f->width-- - ft_max(copy, length) - i > 0)
		f->nprinted += write(1, &k, 1);
}

static	void			right_aligned_int(t_parser *f, int length, char *s)
{
	int		i;
	char	k;

	k = ' ';
	i = 0;
	if (f->precision < -1)
		f->precision = -1;
	if (f->beforeNum)
		i = 1;
	if ((f->flags & ZFL) && (f->precision > f->width || f->precision == -1))
	    k = '0';
	if ((k == '0') && (f->beforeNum == '-' || f->beforeNum == '+'))
	    f->nprinted += write(1, &f->beforeNum, 1);
    if (f->beforeNum == ' ')
    	f->nprinted += write(1, &f->beforeNum, 1);
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
    if ((k == ' ') && (f->beforeNum == '-' || f->beforeNum == '+'))
    	f->nprinted += write(1, &f->beforeNum, 1);
	while (f->precision > length && f->precision--)
		f->nprinted += write(1, "0", 1);
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}

static long long int	cast_size_int(t_parser *f, va_list ap)
{
	if (f->size == 0)
		return ((int)va_arg(ap, int));
	else if (f->size == H)
		return ((short)va_arg(ap, int));
	else if (f->size == HH)
		return ((signed char)va_arg(ap, int));
	else if (f->size == L)
		return ((long int)va_arg(ap, long int));
	else if (f->size == LL)
		return ((long long int)va_arg(ap, long long int));
	else
		return (0);
}

void					ifint(t_parser *f, va_list ap)
{
	long long int	number;
	char			*s;

	number = cast_size_int(f, ap);
	if (number == LLONG_MIN && (f->beforeNum = '-'))
		s = ft_strdup("9223372036854775808");
	else
	{
		if (number < 0)
		{
			number *= -1;
			f->beforeNum = '-';
		}
		s = ft_llitoa(number);
	}
    if ((f->flags & SFL) && !f->beforeNum)
        f->beforeNum = ' ';
	if (f->flags & MFL)
		left_aligned_int(f, ft_strlen(s), s);
	else if (!(f->flags & MFL))
		right_aligned_int(f, ft_strlen(s), s);
	free(s);
}
