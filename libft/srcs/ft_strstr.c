/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:59:50 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/15 19:59:43 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int temp;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		temp = i;
		while (haystack[i] == needle[j])
		{
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
