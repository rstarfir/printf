/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:47:12 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/13 20:54:51 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while ((*s1 || *s2) && n--)
		{
			if ((unsigned char)*s1 != (unsigned char)*s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
	return (0);
}
