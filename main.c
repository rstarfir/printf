/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:20:09 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/15 17:42:03 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "printf.h"
int parsel2(t_parser *f, va_list ap);

int formatparse(t_parser *list, va_list ap)
{
	list->nprinted = 0;
	list->i = 0;
	list->flags[MFL] = 0;
	list->flags[PFL] = 0;
	list->flags[ZFL] = ' ';
	list->flags[OFL] = 0;
	list->width = 0;
	list->precision = 0;
	list->size = 0;
	while (list->format[list->i] != '\0')
	{
		//ft_putstr("I was here");
		if (list->format[list->i] != '%' && list->format[list->i]) // && format[pos] ???? зачем?
		{	
			//ft_putstr("here");
			list->nprinted += write(1, &(list->format[list->i]), 1);
		}
		else if (list->format[list->i] == '%')
		{
			//ft_putstr("here");
			if (!ft_strchr(ALLSYMBOLS, list->format[list->i + 1]))
				break;
			while (ft_strchr(ALLSYMBOLS, list->format[list->i + 1]))
			{
				//ft_putstr("tut");
				list->i++;
				if (ft_strchr("cspdiouxXfyb%", list->format[list->i]))
				{
					list->i = parsel2(list, ap) + 2;
					//ft_putstr("tut");
					break;
				}
				else
					list->i = parsel2(list, ap);
			}
			//ft_putnbr(list->format[list->i]);
			continue;
		}
		list->i++;
	}
	//ft_putstr("tuta");
	return (list->nprinted);
}

int parsel2(t_parser *f, va_list ap)
{

	if (!ft_strchr("cspdiouxXfyb%", f->format[f->i]))
	{
		modifiers(f, ap);
		//ft_putnbr(f->format[f->i]);
	}
	else if (ft_strchr("cspdiouxXfyb%", f->format[f->i]))
	{
		//ft_putstr("was here");
		//ft_putnbr(f->format[f->i]);
		conversions(f->format[f->i], ap, f);
		//ft_putnbr(f->format[f->i - 1]);
		//bezerostruct2(f);
	}
	return (f->i - 1);
}

void	conversions(char c, va_list ap, t_parser *f)
{
	//ft_putstr("debug");
	if (c == 'd' || c == 'i')
		ifint (f, ap);
	//if (c == 'c')
	//	ifchar(f, ap);
	//else if (c == 's')
	//	ifstring(f, ap);
	//else if (c == 'p')
	//	ifpointer(f, ap, 2); //else if (c == 'o')
	//	ifoctal(f, ap);
	//else if (c == 'u')
	//	ifudecint(f, ap);
	//else if (c == 'x' || c == 'X')
	//	ifhex(f, ap, c);
	//else if (c == 'f')
	//	iffloat(f, ap);
	//else if (c == '%')
	//	ifpercent(f);
	//else if (c == 'y')
	//	ifcat();
	//else if (c == 'b')
	//	ifbinary(f, ap);
	//f->i--;
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
	numchar = formatparse(&list, argptr);
	//va_arg(argptr, int);
	va_end(argptr);
	return (numchar);
}

int main(void)
{
	//printf("%0+-+5d", 345);
	//printf("%+d", 345);
	//printf("\n%*5d", 3, 17);
	//printf("\n%-5d", 345);
	ft_printf("%-d", 345);
	return (0);
}
