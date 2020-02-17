/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:44:44 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:58:16 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	char	*temp;

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

char	*ft_strjoinf(char *s1, char *s2,
		char *str_for_free1, char *str_for_free2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str_for_free1)
		free(s1);
	if (str_for_free2)
		free(s2);
	return (str);
}

char	*ft_strndupf(const char *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s1)
	{
		if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		while (s1[i] != '\0' && n--)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
		free((char *)s1);
		return (ptr);
	}
	return (NULL);
}
