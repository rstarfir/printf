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

void checkflags(t_parser *f)
{
	while (1)
	{
		if (f->format[f->i] == '+')
			f->flags[PFL] = '+'; // изначально f->flags[PFL] проинициализировать нулем
		else if (f->format[f->i] == '-')
			f->flags[MFL] = 1;
		else if (f->format[f->i] == '#')
			f->flags[OFL] = 1;
		else if (f->format[f->i] == '0')
			f->flags[ZFL] = 1;
		else if (f->format[f->i] == ' ')
		{
			if (f->flags[PFL] == 0)
			f->flags[PFL] = ' ';
		}
		else
			break;
		f->i++;
	}
}

void	checkwidth(t_parser *f, va_list ap)
{
	if (ft_isdigit(f->format[f->i]))
	{
		while(ft_isdigit(f->format[f->i]))
		{
			f->width = 10 * f->width + f->format[f->i] - '0';
			f->i++;	
		}
	}
	else if (f->format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		f->i++;
		if (f->width < 0)
		{
			f->flags[MFL] *= -1;
			f->width *= -1;
		}
	}

}

void	checkprecision(t_parser *f, va_list ap)
{
	if (f->format[f->i] == '.')
	{
		f->i++;
		if (ft_isdigit(f->format[f->i]))
		{
			f->precision = 0; // изначально precision проинициализировать -1
			while (ft_isdigit(f->format[f->i]))
			{
				f->precision = 10 * f->precision + f->format[f->i] - '0';
				f->i++;
			}
			
		}
		else if (f->format[f->i] == '*')
		{
			f->precision = va_arg(ap, int);
			f->i++;
		}

	}
}

void		checksize(t_parser *f)
{	
	if (f->format[f->i] == 'h')
	{
		if (f->format[f->i + 1] == 'h')
		{
			f->size = HH;
			f->i++;
		}
		else
			f->size = H;
	}
	else if (f->format[f->i] == 'l')
	{
		if (f->format[f->i + 1] == 'l')
		{
			f->size = LL;
			f->i++;
		}
		else
			f->size = L; 
	}
}

void		modifiers(t_parser *f, va_list ap)
{
	checkflags(f);
	checkwidth(f, ap);
	checkprecision(f, ap);
	checksize(f);
}

