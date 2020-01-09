/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:12:57 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/27 17:48:29 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *s1, size_t n1, const void *s2, size_t n2)
{
	unsigned char	*s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_memalloc(n1 + n2 + 1)))
		return (NULL);
	ft_memcpy(s3, s1, n1);
	ft_memcat(s3, n1, s2, n2);
	return (s3);
}
