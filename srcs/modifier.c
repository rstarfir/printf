/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:55:59 by rstarfir          #+#    #+#             */
/*   Updated: 2020/01/08 16:41:36 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdarg.h>

static	void	checkflags(t_parser *f)
{
	while (1)
	{
		if (f->format[f->i] == '+')
			f->flags[FSFL] = '+';
		else if (f->format[f->i] == '-')
			f->flags[MFL] = 1;
		else if (f->format[f->i] == '#')
			f->flags[OFL] = 1;
		else if (f->format[f->i] == '0')
			f->flags[ZFL] = 1;
		else if (f->format[f->i] == ' ')
		{
			if (f->flags[FSFL] == 0)
				f->flags[FSFL] = ' ';
		}
		else
			break ;
		f->i++;
	}
}

static	void	checkwidth(t_parser *f, va_list ap)
{
	widthstar(f, ap);
	if (ft_isdigit(f->format[f->i]))
	{
		f->width = 0;
		while (ft_isdigit(f->format[f->i]))
		{
			f->width = 10 * f->width + f->format[f->i] - '0';
			f->i++;
		}
	}
	if (f->format[f->i] == '*')
	{
		while (f->format[f->i] == '*')
			f->i++;
	}
}

static	void	checkprecision(t_parser *f, va_list ap)
{
	if (f->format[f->i] == '.')
	{
		f->precision = 0;
		f->i++;
		if (ft_isdigit(f->format[f->i]))
		{
			while (ft_isdigit(f->format[f->i]))
			{
				f->double_prec = 10 * f->double_prec + f->format[f->i] - '0';
				f->precision = 10 * f->precision + f->format[f->i] - '0';
				f->i++;
			}
		}
		else if (f->format[f->i] == '*')
		{
			f->precision = va_arg(ap, long double);
			f->double_prec = f->precision;
			f->i++;
		}
	}
}

static	void	checksize(t_parser *f)
{
	if (f->format[f->i] == 'h')
	{
		f->i++;
		if (f->format[f->i] == 'h')
		{
			f->size = HH;
			f->i++;
		}
		else
			f->size = H;
	}
	else if (f->format[f->i] == 'l')
	{
		f->i++;
		if (f->format[f->i] == 'l')
		{
			f->size = LL;
			f->i++;
		}
		else
			f->size = L;
	}
	else if (f->format[f->i] == 'L')
	{
		f->size = UCL;
		f->i++;
	}
}

void			modifiers(t_parser *f, va_list ap)
{
	checkflags(f);
	checkwidth(f, ap);
	checkprecision(f, ap);
	checksize(f);
}
