/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:58:12 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/25 11:43:31 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpad_right(char **str, int c, size_t len)
{
	char	*append;

	if (!str || !len)
		return (NULL);
	if (!(append = ft_strcnew(len, c)))
		return (NULL);
	ft_strappend(str, append);
	ft_strdel(&append);
	return (*str);
}
