/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:11:16 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 18:43:33 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend(char **str, const char *append)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = *str;
	*str = ft_strjoin(tmp, append); // Тут появилась точка
	ft_strdel(&tmp);
	return (*str);
}
