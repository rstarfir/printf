/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:46:14 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/23 17:37:28 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digits_base(intmax_t n, int radix)
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
