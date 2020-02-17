/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:39:49 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:59:15 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void				put_oct_hex(t_parser *f, char flag, char *s)
{
	if ((f->flags & OFL) && flag == 'x' && *s != '0')
		f->nprinted += write(1, "0x", 2);
	else if ((f->flags & OFL) && flag == 'X' && *s != '0')
		f->nprinted += write(1, "0X", 2);
}

static	void				left_hex(t_parser *f, int length, char *s, char fl)
{
	int i;
	int copyprec;

	copyprec = f->precision;
	i = 0;
	if (!(length == 1 && *s == '0'))
	{
		if (f->flags & OFL)
			i += 2;
		put_oct_hex(f, fl, s);
	}
	while (f->precision-- > length)
		f->nprinted += write(1, "0", 1);
	if (copyprec != 0 || *s != '0')
		f->nprinted += write(1, s, length);
	if (length == 1 && copyprec == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(copyprec, length) - i > 0)
		f->nprinted += write(1, " ", 1);
}

static	void				right_hex(t_parser *f, int length, char *s, char fl)
{
	int		i;
	char	k;

	k = ' ';
	i = 0;
	if ((f->flags & OFL) && *s != '0')
		i += 2;
	if ((f->flags & ZFL) && ((f->precision > f->width) || (f->precision == -1)))
		k = '0';
	if (k == '0')
		put_oct_hex(f, fl, s);
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
	if (k == ' ')
		put_oct_hex(f, fl, s);
	while (f->precision > length && f->precision--)
		f->nprinted += write(1, "0", 1);
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}

static unsigned long long	cast_size_hex(t_parser *f, va_list ap)
{
	if (f->size == 0)
		return (va_arg(ap, t_uint));
	else if (f->size == H)
		return ((t_usint)va_arg(ap, t_uint));
	else if (f->size == HH)
		return ((t_uchar)va_arg(ap, t_uint));
	else if (f->size == L)
		return (t_ulint)(va_arg(ap, t_ulint));
	else if (f->size == LL)
		return (t_ullint)(va_arg(ap, t_ullint));
	else
		return (0);
}

void						ifhex(t_parser *f, va_list ap, char c)
{
	t_ullint	number;
	char		*s;

	number = cast_size_hex(f, ap);
	if (c == 'x' || c == 'X')
	{
		if (number == ULONG_MAX && c == 'x')
			s = ft_strdup("ffffffffffffffff");
		else if (number == ULONG_MAX && c == 'X')
			s = ft_strdup("FFFFFFFFFFFFFFFF");
	}
	if (c == 'x')
		s = ft_itoabase_unsigned(number, 16);
	else if (c == 'X')
		s = ft_toupperstring(ft_itoabase_unsigned(number, 16));
	if (f->flags & MFL)
		left_hex(f, ft_strlen(s), s, c);
	else
		right_hex(f, ft_strlen(s), s, c);
	free(s);
}
