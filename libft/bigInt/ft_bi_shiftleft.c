/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_shiftleft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:41:53 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void		ft_bigint_shiftleft(t_bigint *bi, t_uint shift)
{
	t_ulint temp;
	int		i;

	while (shift)
	{
		i = bi->length - 1;
		while (i >= 0)
		{
			temp = ((t_ulint)bi->blocks[i] << 1);
			if (temp > 0xFFFFFFFF)
			{
				bi->blocks[i] = (temp & 0xFFFFFFFF);
				bi->blocks[i + 1] += 1;
				if (i == (int)(bi->length - 1))
					bi->length++;
			}
			else
				bi->blocks[i] = temp;
			i--;
		}
		shift--;
	}
}
