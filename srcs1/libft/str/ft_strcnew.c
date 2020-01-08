/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:51:20 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 20:17:31 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

char		*ft_strcnew(size_t size, int c)
{
	char	*str;

	if (size == ULLONG_MAX
			|| !(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size] = 0;
	ft_memset(str, c, size);
	return (str);
}
