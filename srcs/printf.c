/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hthunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:04:14 by hthunder          #+#    #+#             */
/*   Updated: 2019/12/27 13:04:19 by hthunder         ###   ########.fr       */
=======
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:41:52 by rstarfir          #+#    #+#             */
/*   Updated: 2020/01/08 16:42:10 by rstarfir         ###   ########.fr       */
>>>>>>> e0892d03f9fa091609c06ab8ee7ca958648cfc79
/*                                                                            */
/* ************************************************************************** */


#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
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
/*
int parsel2(t_parser *f, va_list ap)
{

	if (!ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		modifiers(f, ap);
	else if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		conversions(f->format[f->i], ap, f);
	return (f->i - 1);
}

int formatparse(t_parser *list, va_list ap)
{
	list->nprinted = 0;
	list->i = 0;
	list->flags[MFL] = 0;
	list->flags[FSFL] = 0;
	list->flags[ZFL] = ' ';
	list->flags[OFL] = 0;
	list->width = 0;
	//list->precision = -2;
	list->precision = -1;
	list->double_prec = 6;
	list->size = 0;
	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] != '%' && list->format[list->i]) // && format[pos] ???? зачем?
		{
			list->nprinted += write(1, &(list->format[list->i]), 1);
		}
		else if (list->format[list->i] == '%')
		{
			if (!ft_strchr(ALL, list->format[list->i + 1]))
				break;
			while (ft_strchr(ALL, list->format[list->i + 1]))
			{
				list->i++;
				if (ft_strchr("cspdiouxXfyb%", list->format[list->i]))
				{
					list->i = parsel2(list, ap) + 2;
					break;
				}
				else

					list->i = parsel2(list, ap);
			}
			continue;
		}
		list->i++;
	}
	return (list->nprinted);
}
*/

<<<<<<< HEAD
=======
int parsel2(t_parser *f, va_list ap)
{
	if (!ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		{
			////trouble in parcer here
			modifiers(f, ap);
		}
	else if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
			conversions(f->format[f->i], ap, f);
	return (f->i - 1);
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
	else if (c == 'f')
		iffloat(f, ap);
	else if (c == '%')
		ifpercent(f);
}
>>>>>>> e0892d03f9fa091609c06ab8ee7ca958648cfc79

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
