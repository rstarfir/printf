/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_shiftleft.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:47:49 by jkettani          #+#    #+#             */
/*   Updated: 2020/01/04 20:39:20 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint		*ft_bigint_shiftleft(t_bigint *result, t_uint shift)//result = val_numerator | shift = val_expon 
{
	t_uint		i;
	int			block_size;

	if (!shift)
		return (result);
	i = BIGINT_SIZE;
	block_size = BIGINT_BLOCK_SIZE;
	if (!(shift % block_size))
		while (--i >= (shift / block_size))
			result->blocks[i] = result->blocks[i - (shift / block_size)];
	else
	{
		while (--i >= (shift / block_size + 1))
			result->blocks[i] = (result->blocks[i - (shift / block_size + 1)]
				>> (block_size - (shift % block_size)))
				| (result->blocks[i - shift / block_size]
					<< (shift % block_size));
		result->blocks[i] = result->blocks[i - shift / block_size]
								<< (shift % block_size);
	}
	i = !(shift % block_size) ? i + 1 : i;
	while (i--)
		result->blocks[i] = 0;
	result->length = ft_bigint_size(result);
	return (result);
}
