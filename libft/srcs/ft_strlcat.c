/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:24:29 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/15 22:12:56 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t buff, size_t initdst)
{
	if (buff < initdst)
		return (buff);
	else
		return (initdst);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t retval;
	size_t i;
	size_t n;

	i = 0;
	n = size;
	retval = min(size, ft_strlen(dst)) + ft_strlen(src);
	while (dst[i] != '\0' && n--)
		i++;
	n = size - i;
	dst = dst + i;
	if (n != 0)
	{
		while (*src != '\0')
		{
			if (n != 1)
			{
				*dst++ = *src;
				n--;
			}
			src++;
		}
		*dst = '\0';
	}
	return (retval);
}
