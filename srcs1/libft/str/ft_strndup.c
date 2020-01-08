/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:42:58 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/11 13:56:11 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	size_t	s1_len;
	size_t	size;
	char	*s2;

	s1_len = ft_strlen(s1);
	size = (s1_len <= len) ? s1_len : len;
	s2 = ft_memalloc(sizeof(*s2) * (size + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
