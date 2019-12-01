/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifstring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:40:18 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:40:20 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	void	left_aligned_str(t_parser *f, int length, char *s)
{
	char	k;
	int		copylen;
	int		copyprec;

	k = ' ';
	copylen = length;
	copyprec = f->precision;
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (length-- > 0)
	{
		if (f->precision < 0)
			f->nprinted += write(1, s, 1);
		else if (f->precision > 0 && f->precision--)
			f->nprinted += write(1, s, 1);
		s++;
	}
	if (f->flags[ZFL] == 1 && ((f->precision > f->width)
	|| (f->precision == -1)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(copyprec, copylen) > 0)
		f->nprinted += write(1, &k, 1);
}

static	void	right_aligned_str(t_parser *f, int length, char *s)
{
	char k;

	k = ' ';
	if (f->flags[ZFL] == 1 && (f->precision > f->width || f->precision == -1))
		if ((k = '0') && f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(f->precision, length) > 0)
		f->nprinted += write(1, &k, 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
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
	s = (char *)va_arg(ap, char *);
	if (!s)
	{
		s = ft_strdup("(null)");
		flag = 1;
	}
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned_str(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned_str(f, ft_strlen(s), s);
	if (flag == 1)
		free(s);
}
