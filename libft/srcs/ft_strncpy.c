/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:17:19 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/09 14:30:19 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (j < len)
	{
		if (src[i] != '\0')
		{
			dst[j] = src[i];
			i++;
		}
		else
			dst[j] = '\0';
		j++;
	}
	return (dst);
}
