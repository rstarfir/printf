/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:19:46 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/13 16:21:41 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strclcat(char *dst, size_t dst_size, char c, size_t size)
{
	char	*insert;
	size_t	ret;

	if (!(insert = ft_strcnew(size, c)))
		return (ft_strlen(dst));
	ret = ft_strlcat(dst, insert, dst_size);
	ft_strdel(&insert);
	return (ret);
}
