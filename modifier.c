/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:55:59 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/15 21:33:44 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	<stdarg.h>

void		checkflags(t_parser *f)
{
	while (ft_strchr("+-#0 ", format[f->i]))
	{
		if (format[f->i] == '+')
			f->minus = 1;
		if (format[f->i] == '-')
			f->plus = 1;
		if (format[f->i] == '#')
			f->space = 1;
		if (format[f->i] == '0')
			f->hash = 1;
		if (format[f->i] == ' ')
			f->zero = 1;
		f->i++;
	}
	if (f->plus == 1)
		f->space = 0;
}

int		findstar(t_parser *f, va_list ap)
{
	int		ast;

	ast = 0;
	if (format[f->i] == '*')
	{
		ast = 1;
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->flags[MFL] = 1;
			f->width = -(f->width);
		}
		f->i++;
	}
	return (ast);
}

void		checkwidth(t_parser *f, va_list ap)
{
	if (!findstar(f, ap))
		if (f->format[f->i] >= '0' && f->format[f->i] <= '9')
		{
			f->width = ft_atoi(&format[f->i]);
			while (f->format[f->i] >= '0' && f->format[f->i] <= '9')
				f->i++;
		}
}

void		checkprecision(t_parser *f, va_list ap)
{
	if (f->format[f->i] == '.')
	{
		f->i++;
		if(!findstar(f, ap))
			if (f->format[f->i] >= '0' && f->format[f->i] <= '9')
			{
				f->width = ft_atoi(&format[f->i]);
				while (f->format[f->i] >= '0' && f->format[f->i] <= '9')
					f->i++;
			}
	}
}

void		checklength(t_parser *f, int i)
{	
	i = f->i;
	if (ft_strchr("hlLjz", format[i]))
	{
		if (f->format[f->i] == 'h')
		{
			if (f->format[f->i + 1] == 'h')
				f->length = HH;
			else if (f->format[f->i - 1] != 'h')
				f->length = H;
		}
		if (f->format[f->i] == 'l')
		{
			if (f->format[f->i + 1] == 'l')
				f->length = LL;
			else if (f->format[f->i - 1] != 'l')
				f->length = L;
		}
		if (f->format[f->i] == 'L')
			f->length = BIGL;
	}
	while (ft_strchr("hlLjz", format[f->i]))
		f->i++;
	f->i = i;
}

void		modifiers(t_parser *f, va_list *ap)
{
	checkflags(f);
	checkwidth(f, ap);
	checkprecision(f, ap, 0);
	checksize(f, 0);
}

