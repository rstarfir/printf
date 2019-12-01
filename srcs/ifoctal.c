/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifoctal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:04 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:40:06 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdarg.h>
#include <limits.h>

static	void	put_oct_octal(t_parser *f, char *s)
{
	if (f->flags[OFL] == 1 && (f->precision == 0 || *s != '0'))
		f->nprinted += write(1, "0", 1);
	else
		f->flags[OFL] = 0;
}

static	void	left_aligned_oct(t_parser *f, int length, char *s)
{
	int i;
	int copyprec;

	copyprec = f->precision;
	i = 0;
	if ((*s != '0' || copyprec == 0) && (copyprec <= length))
		if (f->flags[OFL] == 1)
		{
			i++;
			f->nprinted += write(1, "0", 1);
		}
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (copyprec != 0)
		f->nprinted += write(1, s, length);
	if (length == 1 && copyprec == 0 && *s == '0')
		length--;
	while (f->width - ft_max(copyprec, length) - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

static	void	right_aligned_oct(t_parser *f, int length, char *s)
{
	int		i;
	char	k;

	k = ' ';
	i = 0;
	if (f->flags[OFL] == 1 && (f->precision != -1 || *s != '0')
	&& (f->precision < length))
		i++;
	if (f->flags[ZFL] == 1 && (f->precision > f->width || f->precision == -1))
		k = '0';
	if (k == '0')
		put_oct_octal(f, s);
	if (f->precision == 0 && *s == '0')
		length--;
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
	if (k == ' ')
		put_oct_octal(f, s);
	while (f->precision > length + f->flags[OFL])
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}

void			ifoctal(t_parser *f, va_list ap)
{
	unsigned long long int	number;
	char					*s;

	if (f->size == 0)
		number = va_arg(ap, unsigned int);
	else if (f->size == H)
		number = (unsigned short)va_arg(ap, unsigned int);
	else if (f->size == HH)
		number = (unsigned char)va_arg(ap, unsigned int);
	else if (f->size == L)
		number = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (f->size == LL)
		number = (unsigned long long int)va_arg(ap, unsigned long long int);
	s = ft_itoabase_unsigned(number, 8);
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned_oct(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned_oct(f, ft_strlen(s), s);
	free(s);
}
