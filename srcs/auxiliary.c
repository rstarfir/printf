/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:15:11 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 20:16:49 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	widthstar(t_parser *f, va_list ap)
{
	if (f->format[f->i] == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->flags |= MFL;
			f->width = -(f->width);
		}
		while (f->format[f->i] == '*')
			f->i++;
	}
}

char	*ft_toupperstring(char *c)
{
	char *temp;

	temp = c;
	if (c)
	{
		while (*c)
		{
			if (*c > 96 && *c < 123)
				*c = *c - 32;
			c++;
		}
		return (temp);
	}
	else
		return (NULL);
}
