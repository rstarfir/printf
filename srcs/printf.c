/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:20:09 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/21 20:56:29 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "../includes/printf.h"
int parsel2(t_parser *f, va_list ap);

void	zerostruct(t_parser *f)
{
	f->flags[MFL] = 0;
	f->flags[FSFL] = 0;
	f->flags[ZFL] = ' ';
	f->flags[OFL] = 0;
	f->width = 0;
	f->precision = 0;
	f->size = 0;
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
	list->precision = -2;
	list->size = 0;
	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] != '%' && list->format[list->i]) // && format[pos] ???? зачем?
		{	
			list->nprinted += write(1, &(list->format[list->i]), 1);
		}
		else if (list->format[list->i] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, list->format[list->i + 1]))
				break;
			while (ft_strchr(ALLSYMBOLS, list->format[list->i + 1]))
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

int parsel2(t_parser *f, va_list ap)
{

	if (!ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		modifiers(f, ap);
	else if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
		conversions(f->format[f->i], ap, f);
	return (f->i - 1);
}

void	conversions(char c, va_list ap, t_parser *f)
{
	if (c == 'd' || c == 'i')
		ifint (f, ap);
	else if (c == 'c')
		ifchar(f, ap);
	else if (c == 's')
		ifstring(f, ap);
	else if (c == 'p')
		ifpointer(f, ap);
	//	ifpointer(f, ap, 2); 
	else if (c == 'o')
		ifoctal(f, ap);
	else if (c == 'u')
		ifudecint(f, ap);
	else if (c == 'x' || c == 'X')
		ifhex(f, ap, c);
		//ifhex(f, ap, c);
	//else if (c == 'f')
	//	iffloat(f, ap);
	else if (c == '%')
		ifpercent(f);
	//else if (c == 'y')
	//	ifcat();
	//else if (c == 'b')
	//	ifbinary(f, ap);
	zerostruct(f);
}

int ft_printf(const char *format, ...)
{
	int 		numchar;
	t_parser	list;

	numchar = 0;
	if (!format)
		return (0);
	list.format = format;
	va_list argptr;
	va_start(argptr, format);
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	else
		numchar = formatparse(&list, argptr);
	va_end(argptr);
	return (numchar);
}
