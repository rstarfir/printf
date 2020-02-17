/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:10:33 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 15:10:40 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
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
		return (ptr);
	}
	return (NULL);
}
