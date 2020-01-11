/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifudecint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:28 by hthunder          #+#    #+#             */
/*   Updated: 2020/01/09 19:12:53 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	void	left_aligned_uint(t_parser *f, int length, char *s)
{
	char	k;
	int		copy;

	k = ' ';
	copy = f->precision;
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
    if (f->flags & ZFL)
        k = '0';
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(copy, length) > 0)
		f->nprinted += write(1, &k, 1);
}

static	void	right_aligned_uint(t_parser *f, int length, char *s)
{
	char k;

	k = ' ';
	if (f->precision < -1)
		f->precision = -1;
    if ((f->flags & ZFL) && ((f->precision > f->width)
                               || (f->precision == -1)))
        k = '0';
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(f->precision, length) > 0)
		f->nprinted += write(1, &k, 1);
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}

void			ifudecint(t_parser *f, va_list ap)
{
	t_ullint	number;
	char					*s;

	if (f->size == 0)
		number = va_arg(ap, t_uint);
	else if (f->size == H)
		number = (t_usint)va_arg(ap, t_uint);
	else if (f->size == HH)
		number = (t_uchar)va_arg(ap, t_uint);
	else if (f->size == L)
		number = (t_ulint)va_arg(ap, t_ulint);
	else if (f->size == LL)
		number = (t_ullint)va_arg(ap, t_ullint);
	s = ft_itoabase_unsigned(number, 10);
    if (f->flags & MFL)
    {
        f->flags &= 0xFFFFFFFF - ZFL;
        left_aligned_uint(f, ft_strlen(s), s);
    }
	else
	    right_aligned_uint(f, ft_strlen(s), s);
	free(s);
}
