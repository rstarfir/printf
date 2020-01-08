/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:18:49 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 10:06:03 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcat(void *s1, size_t n1, const void *s2, size_t n2)
{
	unsigned char		*tmp_s1;
	const unsigned char *tmp_s2;
	size_t				i;

	i = 0;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	while (i < n2)
	{
		tmp_s1[n1 + i] = tmp_s2[i];
		i++;
	}
	return (s1);
}
