/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:34:17 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 16:49:07 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Apply the f function to each character of the string until the return value
** of f is zero, and returns a pointer to the character where it stopped.
** Exemple: if f = ft_isdigit, all digits characters are skipped until a
**          non-digit character is found.
*/

char		*ft_strskip(const char *str, int (*f)(int))
{
	if (!str)
		return (NULL);
	while (*str && (*f)(*str))
		++str;
	return ((char *)str);
}
