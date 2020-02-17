/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:18 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:59:36 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	left_aligned_str(t_parser *f, int length, char *s)
{
	int		copylen;
	int		copyprec;

	copylen = length;
	copyprec = f->precision;
	if (f->before_num == '-')
		f->nprinted += write(1, &f->before_num, 1);
	while (length-- > 0)
	{
		if (f->precision < 0)
			f->nprinted += write(1, s, 1);
		else if (f->precision > 0 && f->precision--)
			f->nprinted += write(1, s, 1);
		s++;
	}
	if ((f->flags & ZFL) && ((f->precision > f->width)
	|| (f->precision == -1)))
		if (f->before_num == '-')
			f->nprinted += write(1, &f->before_num, 1);
	while (f->width-- - ft_min(copyprec, copylen) > 0)
		f->nprinted += write(1, " ", 1);
}

static	void	right_aligned_str(t_parser *f, int length, char *s)
{
	char k;

	k = ' ';
	if ((f->flags & ZFL) && (f->precision > f->width || f->precision == -1))
		if ((k = '0') && f->before_num == '-')
			f->nprinted += write(1, &f->before_num, 1);
	if (f->before_num == ' ')
		f->nprinted += write(1, &f->before_num, 1);
	while (f->width-- - ft_min(f->precision, length) > 0)
		f->nprinted += write(1, &k, 1);
	if (f->before_num == '-' && k == ' ')
		f->nprinted += write(1, &f->before_num, 1);
	while (length-- > 0)
	{
		if (f->precision < 0)
		{
			f->nprinted += write(1, s, 1);
			s++;
		}
		else if (f->precision > 0 && f->precision--)
		{
			f->nprinted += write(1, s, 1);
			s++;
		}
	}
}

void			ifstring(t_parser *f, va_list ap)
{
	char	*s;
	int		flag;

	flag = 0;
	if (f->size == L)
	{
		s = (char *)malloc(5 * sizeof(char));
		f->nprinted = utf8_encode(s, (t_uint)va_arg(ap, t_uint));
		flag = 1;
	}
	else
		s = (char *)va_arg(ap, char *);
	if (!s)
	{
		s = ft_strdup("(null)");
		flag = 1;
	}
	if (f->flags & MFL)
		left_aligned_str(f, ft_strlen(s), s);
	else
		right_aligned_str(f, ft_strlen(s), s);
	if (flag == 1)
		free(s);
}
