/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifbinary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:53:06 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:58:57 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	left_aligned_binary(t_parser *f, int length, char *s)
{
	f->nprinted += write(1, s, length);
	if (f->flags & OFL)
		f->nprinted += write(1, "b", 1);
	while (f->width-- - length - !!(f->flags & OFL) > 0)
		f->nprinted += write(1, " ", 1);
}

static	void	right_aligned_binary(t_parser *f, int length, char *s)
{
	while (f->width-- - length - !!(f->flags & OFL) > 0)
		f->nprinted += write(1, " ", 1);
	f->nprinted += write(1, s, length);
	if (f->flags & OFL)
		f->nprinted += write(1, "b", 1);
}

void			ifbinary(t_parser *f, va_list ap)
{
	t_ullint	number;
	char		*s;

	if (f->size == 0)
		number = (t_uint)va_arg(ap, t_uint);
	else if (f->size == H)
		number = (t_usint)va_arg(ap, t_uint);
	else if (f->size == HH)
		number = (t_uchar)va_arg(ap, t_uint);
	else if (f->size == L)
		number = (t_ulint)va_arg(ap, t_ulint);
	else if (f->size == LL)
		number = (t_ullint)va_arg(ap, t_ullint);
	s = ft_itoabase_unsigned(number, 2);
	if (f->flags & MFL)
		left_aligned_binary(f, ft_strlen(s), s);
	else
		right_aligned_binary(f, ft_strlen(s), s);
	free(s);
}
