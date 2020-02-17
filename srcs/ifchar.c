/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifchar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:39:38 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:59:03 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_min(int one, int two)
{
	if (one < two)
	{
		if (one < 0)
			return (two);
		else
			return (one);
	}
	else
		return (two);
}

void	left_alignedchar(t_parser *f, char c)
{
	int i;

	i = 0;
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, &c, 1);
	while (f->width - 1 - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void	right_alignedchar(t_parser *f, char c)
{
	int		i;
	char	k;

	k = ' ';
	i = 0;
	if (f->flags & ZFL)
		k = '0';
	while (f->width - ft_max(f->precision, 1) - i > 0)
	{
		f->nprinted += write(1, &k, 1);
		f->width--;
	}
	f->nprinted += write(1, &c, 1);
}

void	ifpercent(t_parser *f)
{
	char	c;

	c = '%';
	if (f->flags & MFL)
		left_alignedchar(f, c);
	else
		right_alignedchar(f, c);
}

void	ifchar(t_parser *f, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	if (f->flags & MFL)
		left_alignedchar(f, c);
	else
		right_alignedchar(f, c);
}
