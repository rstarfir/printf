/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifhex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:39:49 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:39:51 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

static	void				left_hex(t_parser *f, int length, char *s, char fl)
{
	int i;
	int copyprec;

	copyprec = f->precision;
	i = 0;
	if (!(length == 1 && *s == '0'))
	{
		if (f->flags[OFL] == 1)
			i += 2;
		if (f->flags[OFL] == 1 && fl == 'x')
			f->nprinted += write(1, "0x", 2);
		else if (f->flags[OFL] == 1 && fl == 'X')
			f->nprinted += write(1, "0X", 2);
	}
	while (f->precision-- > length)
		f->nprinted += write(1, "0", 1);
	if (copyprec != 0)
		f->nprinted += write(1, s, length);
	if (length == 1 && copyprec == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(copyprec, length) - i > 0)
		f->nprinted += write(1, " ", 1);
}

/*
**  if (f->precision < -1) 	для отрицательного wildcard
**	f->precision = -1;
*/

static	void				put_oct(t_parser *f, char flag, char *s)
{
	if (f->flags[OFL] == 1 && flag == 'x' && *s != '0')
		f->nprinted += write(1, "0x", 2);
	else if (f->flags[OFL] == 1 && flag == 'X' && *s != '0')
		f->nprinted += write(1, "0X", 2);
}

static	void				right_hex(t_parser *f, int length, char *s, char fl)
{
	int		i;
	int		z;
	char	k;

	z = 0;
	k = ' ';
	i = 0;
	if (f->flags[OFL] == 1 && *s != '0')
		i += 2;
	if (f->flags[ZFL] && ((f->precision > f->width) || (f->precision == -1)))
		k = '0';
	if (k == '0')
		put_oct(f, fl, s);
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
	if (k == ' ')
		put_oct(f, fl, s);
	while (f->precision > length && f->precision--)
		f->nprinted += write(1, "0", 1);
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}
/*
static	char				*ft_toupperstring(char *c)
{
	char *temp;

	temp = c;
	if (c)
	{
		while (*c)
		{
			if (*c > 96 && *c < 123)
				*c = *c - 32;
			c++;
		}
		return (temp);
	}
	else
		return (NULL);
}*/

static unsigned long long	cast_size(t_parser *f, va_list ap)
{
	if (f->size == 0)
		return (va_arg(ap, unsigned int));
	else if (f->size == H)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (f->size == HH)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (f->size == L)
		return (va_arg(ap, unsigned long int));
	else if (f->size == LL)
		return (va_arg(ap, unsigned long long int));
	else
		return (0);
}

void						ifhex(t_parser *f, va_list ap, char c)
{
	unsigned long long int	number;
	char					*s;

	number = cast_size(f, ap);
	if (c == 'x' || c == 'X')
	{
		if (number == ULONG_MAX && c == 'x')
		{
			f->nprinted += write(1, "ffffffffffffffff", 16);
			return ;
		}
		else if (number == ULONG_MAX && c == 'X')
		{
			f->nprinted += write(1, "FFFFFFFFFFFFFFFF", 16);
			return ;
		}
	}
	if (c == 'x')
		s = ft_itoabase_unsigned(number, 16);
	else if (c == 'X')
		s = ft_toupperstring(ft_itoabase_unsigned(number, 16));
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_hex(f, ft_strlen(s), s, c);
	}
	else if (f->flags[MFL] == 0)
		right_hex(f, ft_strlen(s), s, c);
	free(s);
}
