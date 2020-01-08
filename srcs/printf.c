/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:04:14 by hthunder          #+#    #+#             */
/*   Updated: 2019/12/27 13:04:19 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static	void	zerostruct(t_parser *f)
{
	f->flags[MFL] = 0;
	f->flags[FSFL] = 0;
	f->flags[ZFL] = 0;
	f->flags[OFL] = 0;
	f->width = 0;
	f->precision = -1;
	f->size = 0;
}

void	conversions(char c, va_list ap, t_parser *f)
{
	if (c == 'd' || c == 'i')
		ifint(f, ap);
	else if (c == 'c')
		ifchar(f, ap);
	else if (c == 's')
		ifstring(f, ap);
	else if (c == 'p')
		ifpointer(f, ap);
	else if (c == 'o')
		ifoctal(f, ap);
	else if (c == 'u')
		ifudecint(f, ap);
	else if (c == 'x' || c == 'X')
		ifhex(f, ap, c);
	//else if (c == 'f')
	//	iffloat(f, ap);
	else if (c == '%')
		ifpercent(f);
}

static	int		parsel2(t_parser *f, va_list ap)
{
	if (!ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		modifiers(f, ap);
	else if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
	{
		conversions(f->format[f->i], ap, f);
		zerostruct(f);
	}
	return (f->i - 1);
}

static	int		formatparse(t_parser *f, va_list ap)
{
	while ((f->format)[f->i] != '\0')
	{
		if (f->format[f->i] != '%' && f->format[f->i])
			f->nprinted += write(1, &(f->format[f->i]), 1);
		else if (f->format[f->i] == '%')
		{
			if (!ft_strchr(ALL, f->format[f->i + 1]))
				break ;
			while (f->format[f->i + 1] && ft_strchr(ALL, f->format[f->i + 1]))
			{
				f->i++;
				if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
				{
					f->i = parsel2(f, ap) + 2;
					break ;
				}
				else
					f->i = parsel2(f, ap);
			}
			continue;
		}
		f->i++;
	}
	return (f->nprinted);
}

int				ft_printf(const char *format, ...)
{
	int			numchar;
	t_parser	list;
	va_list		argptr;

	numchar = 0;
	if (!format)
		return (0);
	list.format = format;
	list.nprinted = 0;
	list.i = 0;
	list.flags[MFL] = 0;
	list.flags[FSFL] = 0;
	list.flags[ZFL] = 0;
	list.flags[OFL] = 0;
	list.width = 0;
	list.precision = -1;
	list.size = 0;
	va_start(argptr, format);
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	else
		numchar = formatparse(&list, argptr);
	va_end(argptr);
	return (numchar);
}
