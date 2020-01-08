/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:48:43 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 15:37:32 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strupper(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
	return (str);
}
