/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_uint.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:50:59 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/17 22:51:40 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Multiply a bigint by an unsigned int.
*/

t_bigint		*ft_bigint_multiply_uint(t_bigint *result, t_uint nb)
{
	size_t		i;
	t_ulint		carry;
	t_ulint		res;

	if (nb == 1)
		return (result);
	i = 0;
	carry = 0UL;
	while (i < result->length)
	{
		res = (t_ulint)result->blocks[i] * (t_ulint)nb + carry;
		result->blocks[i] = (t_uint)(res & 0xFFFFFFFFUL);
		carry = res >> 32;
		i++;
	}
	if (carry && i < BIGINT_SIZE)
		result->blocks[i] = (t_uint)(carry & 0xFFFFFFFFUL);
	result->length = ft_bigint_size(result);
	return (result);
}
