/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:42:06 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/17 16:41:55 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	size_t	temp;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		temp = i;
		while (haystack[i] == needle[j])
		{
			if (i == len)
				return (NULL);
			if (needle[j + 1] == '\0')
				return ((char *)&(haystack[temp]));
			i++;
			j++;
		}
		i = temp;
		i++;
	}
	return (NULL);
}
