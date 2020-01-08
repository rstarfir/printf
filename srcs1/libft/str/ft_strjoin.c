/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:58:21 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 18:43:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}
