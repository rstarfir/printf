/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:04:14 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:08:43 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	void	conversions(char c, va_list ap, t_parser *f)
{
	if (c == 'd' || c == 'i')
		ifint(f, ap);
	else if (c == 'c')
		ifchar(f, ap);
	else if (c == '%')
		ifpercent(f);
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
	else if (c == 'f' || c == 'F')
		iffloat(f, ap);
	else if (c == 'b')
		ifbinary(f, ap);
}

static	int		handle_modif_conver(t_parser *f, va_list ap)
{
	if (!ft_strchr("cspdiouxXfFb%", f->format[f->i]))
		modifiers(f, ap);
	else if (ft_strchr("cspdiouxXfFb%", f->format[f->i]))
	{
		conversions(f->format[f->i], ap, f);
		f->before_num = 0;
		f->flags = 0;
		f->width = 0;
		f->precision = -1;
		f->flprecision = 6;
		f->size = 0;
	}
	return (f->i - 1);
}

static	void	call_handlers(t_parser *f, va_list ap)
{
	int	flag;

	flag = 0;
	while (f->format[f->i + 1] && ft_strchr(ALL, f->format[f->i + 1]) && !flag)
	{
		f->i++;
		if (ft_strchr("cspdiouxXfFb%", f->format[f->i]))
		{
			f->i = handle_modif_conver(f, ap) + 2;
			flag = 1;
		}
		else
			f->i = handle_modif_conver(f, ap);
	}
}

static	int		formatparse(t_parser *f, va_list ap)
{
	while ((f->format)[f->i] != '\0')
	{
		if (f->format[f->i] != '%' && f->format[f->i])
		{
			if (f->format[f->i] == '{' && add_color(f->format + f->i, f) > 0)
				continue;
			f->nprinted += write(1, &(f->format[f->i]), 1);
		}
		else if (f->format[f->i] == '%')
		{
			if (!f->format[f->i + 1] || !ft_strchr(ALL, f->format[f->i + 1]))
				break ;
			call_handlers(f, ap);
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

	if (!format)
		return (0);
	list.format = format;
	list.nprinted = 0;
	list.i = 0;
	list.before_num = 0;
	list.flags = 0;
	list.width = 0;
	list.precision = -1;
	list.flprecision = 6;
	list.size = 0;
	va_start(argptr, format);
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	else
		numchar = formatparse(&list, argptr);
	va_end(argptr);
	return (numchar);
}
