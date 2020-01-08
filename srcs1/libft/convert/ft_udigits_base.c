/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udigits_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:43:03 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 17:43:44 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_udigits_base(uintmax_t n, int radix)
{
	int			count;

	if (radix < 1)
		return (-1);
	else if (radix == 1)
		return (n);
	else if (n == 0)
		return (1);
	else
	{
		count = 0;
		while (n != 0)
		{
			count++;
			n /= radix;
		}
	}
	return (count);
}
