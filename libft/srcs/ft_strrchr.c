/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:17:13 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/10 16:07:30 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	char *ptr;

	ptr = NULL;
	while (*s1 != '\0')
	{
		if (*s1 == (char)c)
			ptr = (char *)s1;
		s1++;
	}
	if (*s1 == (char)c)
		ptr = (char *)s1;
	return (ptr);
}
