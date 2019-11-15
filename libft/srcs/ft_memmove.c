/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:05:36 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/15 19:48:57 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *csrc;
	char *cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (csrc == cdst)
		return (dst);
	if (csrc < cdst)
	{
		csrc = csrc + len - 1;
		cdst = cdst + len - 1;
		while (len--)
			*cdst-- = *csrc--;
	}
	else
		while (len--)
			*cdst++ = *csrc++;
	return (dst);
}
