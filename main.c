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

/*char	*ft_itoabase(long long int num, int base); 

int formatparse(t_parser *list, va_list ap, int pos)
{
	while (list->format[pos] != '\0')
	{
		if (list->format[pos] != '%' && list->format[pos]) // && format[pos] ???? зачем?
			list->nprinted += write(1, &(list->format[pos]), 1);
		else if (list->format[pos] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, list->format[pos + 1]))
				break;
			while (ft_strchr(ALLSYMBOLS, list->format[pos + 1]))
			{
				pos = pos + 1;
				if (ft_strchr("cspdiouxXfyb%", list->format[pos]))
				{
					pos = parsel2(list, pos, ap) + 2;
					break;
				}
				else
					pos = parsel2(list, pos, ap);
			}
			continue;
		}
		pos++;
	}
	return (list->nprinted);
}

int parsel2(t_parser *f, int position, va_list ap)
{
	f->i = position;
	if (!ft_strchr("cspdiouxXfyb%", f->format[position]))
		modifiers(f, ap);
	else if (ft_strchr("cspdiouxXfyb%", f->format[position]))
	{
		conversions(f->format[position], ap, f);
		bezerostruct2(f);
	}
	return (f->i - 1);
}

void	conversions(char c, va_list ap, t_parser *f)
{
	if (c == 'c')
		ifchar(f, ap);
	else if (c == 's')
		ifstring(f, ap);
	else if (c == 'p')
		ifpointer(f, ap, 2);
	else if (c == 'd' || c == 'i')
		ifint (f, ap, 0, 0);
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
	else if (c == 'y')
		ifcat();
	else if (c == 'b')
		ifbinary(f, ap);
}

int ft_printf(const char *format, ...)
{
	int 		numchar;
	t_parser	list;
	int			pos;

	pos = 0;
	numchar = 0;
	if (!format)
		return (0);
	list.format = format;
	va_list argptr;
	va_start(argptr, format);
	numchar = formatparse(&list, argptr, pos);
	//va_arg(argptr, int);
	va_end(argptr);
	return (numchar);
}*/

int main(void)
{
	printf("%*d", 5, 34);
	// printf("%5d blablacar", 3450));
	return (0);
}
