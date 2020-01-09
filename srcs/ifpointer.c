/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifpointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:11 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:40:13 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	void	left_aligned_pointer(t_parser *f, int length, char *s)
{
	int i;
	int copyprec;

	copyprec = f->precision;
	i = 2;
	if (f->precision < -1)
		f->precision = -1;
	if (f->flags & OFL)
	    f->nprinted += write(1, "0x", 2);
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, length);
	while (f->width - ft_max(copyprec, length) - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

static	void	right_aligned_pointer(t_parser *f, int length, char *s)
{
	int i;

	i = 2;
	while (f->width - ft_max(f->precision, length) - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	if (f->flags & OFL)
	    f->nprinted += write(1, "0x", 2);
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (*s != '0' || (f->precision != 0))
		f->nprinted += write(1, s, length);
}

void			ifpointer(t_parser *f, va_list ap)
{
	char					*s;
	unsigned long long int	number;

	f->flags |= OFL;
	number = (unsigned long long int)va_arg(ap, void *);
	s = ft_itoabase_unsigned(number, 16);
    if (f->flags & MFL)
        	left_aligned_pointer(f, ft_strlen(s), s);
    else
    	right_aligned_pointer(f, ft_strlen(s), s);
}
